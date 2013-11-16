# $NetBSD: checksum.mk,v 1.20 2013/11/16 15:29:39 jakllsch Exp $
#
# See bsd.checksum.mk for helpful comments.
#

_DIGEST_ALGORITHMS?=		SHA1 RMD160
_PATCH_DIGEST_ALGORITHMS?=	SHA1

# These variables are set by pkgsrc/mk/fetch/bsd.fetch-vars.mk.
#_CKSUMFILES?=	# empty
#_IGNOREFILES?=	# empty

# _COOKIE.checksum
#       The file whose presence determines whether or not the checksum
#	process is run.
#
#	This is not a traditional cookie file.  We do not actually
#	wish to create a cookie file for the completion of the checksum
#	phase because we want to be able to detect if any of the files
#	have changed right up until the distfiles are extracted.
#	Therefore, we use the presence of the cookie file from the
#	"extract" phase to determine whether we need to continue to
#	verify checksums.
#
#	_COOKIE.extract is defined in pkgsrc/mk/extract/extract.mk.
#
_COOKIE.checksum=	${_COOKIE.extract}

_CHECKSUM_CMD=								\
	${PKGSRC_SETENV} DIGEST=${TOOLS_DIGEST:Q} CAT=${TOOLS_CAT:Q}	\
		ECHO=${TOOLS_ECHO:Q} SED=${TOOLS_CMDLINE_SED:Q}		\
		TEST=${TOOLS_TEST:Q}					\
	${SH} ${PKGSRCDIR}/mk/checksum/checksum				\

.if defined(NO_CHECKSUM) || empty(_CKSUMFILES)
checksum checksum-phase:
	@${DO_NADA}
.else
checksum checksum-phase:
	${RUN} set -e;							\
	case ${.TARGET:Q} in						\
	*-phase)	${TEST} ! -f ${_COOKIE.checksum} || exit 0 ;;	\
	esac;								\
	if cd ${DISTDIR} && ${_CHECKSUM_CMD} ${DISTINFO_FILE} ${_CKSUMFILES}; then \
		${TRUE};						\
	else								\
		${ERROR_MSG} "Make sure the Makefile and checksum file (${DISTINFO_FILE})"; \
		${ERROR_MSG} "are up to date.  If you want to override this check, type"; \
		${ERROR_MSG} "\"${MAKE} NO_CHECKSUM=yes [other args]\"."; \
		exit 1;							\
	fi
.endif

_DISTINFO_CMD=	${PKGSRC_SETENV} DIGEST=${TOOLS_DIGEST:Q} SED=${TOOLS_SED:Q} \
			TEST=${TOOLS_TEST:Q} WC=${TOOLS_WC:Q}	\
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

.PHONY: depends-checksum
depends-checksum:
	${RUN}                                                          \
	${_DEPENDS_WALK_CMD} ${PKGPATH} |                               \
	while read dir; do                                              \
		${ECHO} "===> Checksumming for $${dir}" &&              \
		cd ${.CURDIR}/../../$$dir &&                            \
		${RECURSIVE_MAKE} ${MAKEFLAGS} checksum || exit 1;	\
	done
