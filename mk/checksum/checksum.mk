# $NetBSD: checksum.mk,v 1.7 2007/08/16 16:29:27 jlam Exp $
#
# See bsd.checksum.mk for helpful comments.
#

_DIGEST_ALGORITHMS?=		SHA1 RMD160
_PATCH_DIGEST_ALGORITHMS?=	SHA1

# Some developers want to check the distfiles' checksums every time
# a public make target is called. They may set this variable to "yes".
DO_CHECKSUM_REPEATEDLY?=	no

# These variables are set by pkgsrc/mk/fetch/fetch.mk.
#_CKSUMFILES?=	# empty
#_IGNOREFILES?=	# empty

_CHECKSUM_CMD=								\
	${SETENV} DIGEST=${TOOLS_DIGEST:Q} CAT=${TOOLS_CAT:Q}		\
		ECHO=${TOOLS_ECHO:Q} SED=${TOOLS_SED:Q}			\
		TEST=${TOOLS_TEST:Q}					\
	${SH} ${PKGSRCDIR}/mk/checksum/checksum				\

_COOKIE.checksum=	${WRKDIR}/.checksum_done

.PHONY: checksum
checksum: ${_COOKIE.checksum}
${_COOKIE.checksum}:
.for _alg_ in ${_DIGEST_ALGORITHMS}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if cd ${DISTDIR} && ${_CHECKSUM_CMD} -a ${_alg_:Q}		\
		${DISTINFO_FILE} ${_CKSUMFILES}; then			\
		if [ ${DO_CHECKSUM_REPEATEDLY} = no ]; then		\
			${MKDIR} ${.TARGET:H};				\
			${ECHO} ${PKGNAME} > ${.TARGET};		\
		fi;							\
	else								\
		${ERROR_MSG} "Make sure the Makefile and checksum file (${DISTINFO_FILE})"; \
		${ERROR_MSG} "are up to date.  If you want to override this check, type"; \
		${ERROR_MSG} "\"${MAKE} NO_CHECKSUM=yes [other args]\"."; \
		exit 1;							\
	fi
.endfor

_DISTINFO_CMD=	${SETENV} DIGEST=${TOOLS_DIGEST:Q} SED=${TOOLS_SED:Q}	\
			TEST=${TOOLS_TEST:Q} WC=${TOOLS_WC:Q}		\
		${AWK} -f ${PKGSRCDIR}/mk/checksum/distinfo.awk --

.if exists(${DISTDIR})
_DISTINFO_ARGS_COMMON+=	-d ${DISTDIR}
.endif
.if exists(${DISTINFO_FILE})
_DISTINFO_ARGS_COMMON+=	-f ${DISTINFO_FILE}
.endif
.if defined(_DIGEST_ALGORITHMS) && !empty(_DIGEST_ALGORITHMS)
_DISTINFO_ARGS_COMMON+=	${_DIGEST_ALGORITHMS:S/^/-a /}
.endif
.if defined(_PATCH_DIGEST_ALGORITHMS) && !empty(_PATCH_DIGEST_ALGORITHMS)
_DISTINFO_ARGS_COMMON+=	${_PATCH_DIGEST_ALGORITHMS:S/^/-p /}
.endif

.if defined(_CKSUMFILES) && !empty(_CKSUMFILES)
_DISTINFO_ARGS_DISTSUM+=	${_CKSUMFILES:S/^/-c /}
.endif
.if defined(_IGNOREFILES) && !empty(_IGNOREFILES)
_DISTINFO_ARGS_DISTSUM+=	${_IGNOREFILES:S/^/-i /}
.endif

_DISTINFO_ARGS_PATCHSUM+=	${PATCHDIR}/patch-*
_DISTINFO_ARGS_PATCHSUM+=	${PATCHDIR}/emul-*-patch-*

distinfo:
	${RUN}set -e;							\
	newfile=${DISTINFO_FILE}.$$$$;					\
	if ${_DISTINFO_CMD} ${_DISTINFO_ARGS_COMMON}			\
		${_DISTINFO_ARGS_DISTSUM}				\
		${_DISTINFO_ARGS_PATCHSUM} > $$newfile;			\
	then								\
		${RM} -f $$newfile;					\
		${ECHO_MSG} "=> distinfo: unchanged.";			\
	else								\
		${MV} -f $$newfile ${DISTINFO_FILE};			\
	fi

makesum:
	${RUN}set -e;							\
	newfile=${DISTINFO_FILE}.$$$$;					\
	if ${_DISTINFO_CMD} ${_DISTINFO_ARGS_COMMON}			\
		${_DISTINFO_ARGS_DISTSUM} > $$newfile;			\
	then								\
		${RM} -f $$newfile;					\
		${ECHO_MSG} "=> distinfo: distfiles part unchanged.";	\
	else								\
		${MV} -f $$newfile ${DISTINFO_FILE};			\
	fi

makepatchsum:
	${RUN}set -e;							\
	newfile=${DISTINFO_FILE}.$$$$;					\
	if ${_DISTINFO_CMD} ${_DISTINFO_ARGS_COMMON}			\
		${_DISTINFO_ARGS_PATCHSUM} > $$newfile;			\
	then								\
		${RM} -f $$newfile;					\
		${ECHO_MSG} "=> distinfo: patches part unchanged.";	\
	else								\
		${MV} -f $$newfile ${DISTINFO_FILE};			\
	fi
