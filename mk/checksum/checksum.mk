# $NetBSD: checksum.mk,v 1.1 2006/07/13 14:02:34 jlam Exp $

_DIGEST_ALGORITHMS?=		SHA1 RMD160
_PATCH_DIGEST_ALGORITHMS?=	SHA1

# These variables are set by pkgsrc/mk/fetch/fetch.mk.
#_CKSUMFILES?=	# empty
#_IGNOREFILES?=	# empty

######################################################################
### checksum (PUBLIC)
######################################################################
### checksum is a public target to checksum the fetched distfiles
### for the package.
###
_CHECKSUM_CMD=								\
	${SETENV} DIGEST=${TOOLS_DIGEST:Q} CAT=${TOOLS_CAT:Q}		\
		ECHO=${TOOLS_ECHO:Q} TEST=${TOOLS_TEST:Q}		\
	${SH} ${PKGSRCDIR}/mk/checksum/checksum				\

.PHONY: checksum
checksum: fetch
.for _alg_ in ${_DIGEST_ALGORITHMS}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if cd ${DISTDIR} && ${_CHECKSUM_CMD} -a ${_alg_:Q}		\
		${DISTINFO_FILE} ${_CKSUMFILES}; then			\
		${TRUE};						\
	else								\
		${ERROR_MSG} "Make sure the Makefile and checksum file (${DISTINFO_FILE})"; \
		${ERROR_MSG} "are up to date.  If you want to override this check, type"; \
		${ERROR_MSG} "\"${MAKE} NO_CHECKSUM=yes [other args]\"."; \
		exit 1;							\
	fi
.endfor

######################################################################
### makesum (PUBLIC)
######################################################################
### makesum is a public target to add checksums of the distfiles for
### the package to ${DISTINFO_FILE}.
###
.PHONY: makesum
makesum: fetch
	${_PKG_SILENT}${_PKG_DEBUG}set -e;				\
	newfile=${DISTINFO_FILE}.$$$$;					\
	if ${TEST} -f ${DISTINFO_FILE}; then				\
		{ ${GREP} '^.NetBSD' ${DISTINFO_FILE} ||		\
		  ${ECHO} "$$""NetBSD""$$"; } > $$newfile;		\
	else								\
		${ECHO} "$$""NetBSD""$$" > $$newfile;			\
	fi;								\
	${ECHO} "" >> $$newfile;					\
	cd ${DISTDIR};							\
	for sumfile in "" ${_CKSUMFILES}; do				\
		${TEST} -n "$$sumfile" || continue;			\
		for a in "" ${_DIGEST_ALGORITHMS}; do			\
			${TEST} -n "$$a" || continue;			\
			${TOOLS_DIGEST} $$a $$sumfile >> $$newfile;	\
		done;							\
		${WC} -c $$sumfile |					\
		${AWK} '{ print "Size (" $$2 ") = " $$1 " bytes" }'	\
			>> $$newfile;					\
	done;								\
	for ignore in "" ${_IGNOREFILES}; do				\
		${TEST} -n "$$ignore" || continue;			\
		for a in "" ${_DIGEST_ALGORITHMS}; do			\
			${TEST} -n "$$a" || continue;			\
			${ECHO} "$$a ($$ignore) = IGNORE" >> $$newfile;	\
		done;							\
	done;								\
	if ${TEST} -f ${DISTINFO_FILE}; then				\
		${AWK} '$$2 ~ /\(patch-[a-z0-9]+\)/ { print $$0 }'	\
			< ${DISTINFO_FILE} >> $$newfile;		\
	fi;								\
	if ${CMP} -s $$newfile ${DISTINFO_FILE}; then			\
		${RM} -f $$newfile;					\
		${ECHO_MSG} "=> distinfo: distfiles part unchanged.";	\
	else								\
		${MV} -f $$newfile ${DISTINFO_FILE};			\
	fi

######################################################################
### makepatchsum (PUBLIC)
######################################################################
### makepatchsum is a public target to add checksums of the patches
### for the package to ${DISTINFO_FILE}.
###
makepatchsum:
	${_PKG_SILENT}${_PKG_DEBUG}set -e;				\
	newfile=${DISTINFO_FILE}.$$$$;					\
	if ${TEST} -f ${DISTINFO_FILE}; then				\
		${AWK} '$$2 !~ /\(patch-[a-z0-9]+\)/ { print $$0 }'	\
			< ${DISTINFO_FILE} >> $$newfile;		\
	else								\
		${ECHO} "$$""NetBSD""$$" > $$newfile;			\
		${ECHO} "" >> $$newfile;				\
	fi;								\
	if ${TEST} -d ${PATCHDIR}; then					\
		( cd ${PATCHDIR};					\
		  for sumfile in "" patch-*; do				\
			case "$$sumfile" in				\
			""|"patch-*") continue ;;			\
			patch-local-*|*.orig|*.rej|*~) continue ;;	\
			esac;						\
			for a in "" ${_PATCH_DIGEST_ALGORITHMS}; do	\
				${TEST} -n "$$a" || continue;		\
				${ECHO} "$$a ($$sumfile) = `${SED} -e '/\$$NetBSD.*/d' $$sumfile | ${TOOLS_DIGEST} $$a`" >> $$newfile; \
			done;						\
		  done );						\
	fi;								\
	if ${CMP} -s $$newfile ${DISTINFO_FILE}; then			\
		${RM} -f $$newfile;					\
		${ECHO_MSG} "=> distinfo: patches part unchanged.";	\
	else								\
		${MV} $$newfile ${DISTINFO_FILE};			\
	fi
