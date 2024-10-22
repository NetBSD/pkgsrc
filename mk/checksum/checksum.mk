# $NetBSD: checksum.mk,v 1.33 2024/10/22 06:29:21 jperkin Exp $
#
# See bsd.checksum.mk for helpful comments.
#

_DIGEST_ALGORITHMS?=		BLAKE2s SHA512
_PATCH_DIGEST_ALGORITHMS?=	SHA1

# These variables are set by pkgsrc/mk/fetch/bsd.fetch-vars.mk.
#_CKSUMFILES?=	# empty

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

.if !empty(TOOLS_PLATFORM.mktool)
_CHECKSUM_CMD=	${TOOLS_PLATFORM.mktool} checksum
.else
_CHECKSUM_CMD=								\
	${PKGSRC_SETENV}						\
	    DIGEST=${TOOLS_DIGEST:Q} SED=${TOOLS_CMDLINE_SED:Q}		\
	    ${AWK} -f ${PKGSRCDIR}/mk/checksum/checksum.awk --
.endif

.if defined(NO_CHECKSUM) || empty(_CKSUMFILES)
checksum checksum-phase:
	@${DO_NADA}
.else
checksum checksum-phase:
.  if ${USE_TMPFILES} == yes
	${_CKSUMFILES_INPUT::=${_CKSUMFILES_INPUT_cmd:sh}}
.    for file in ${_CKSUMFILES}
	@${ECHO} ${file} >> ${_CKSUMFILES_INPUT}
.    endfor
	${RUN} set -e;							\
	case ${.TARGET:Q} in						\
	*-phase)	${TEST} ! -f ${_COOKIE.checksum} || exit 0 ;;	\
	esac;								\
	if cd ${DISTDIR} && ${_CHECKSUM_CMD} -I ${_CKSUMFILES_INPUT} ${DISTINFO_FILE:tA}; then \
		${TRUE};						\
	else								\
		${ERROR_MSG} "Make sure the Makefile and checksum file (${DISTINFO_FILE})"; \
		${ERROR_MSG} "are up to date.  If you want to override this check, type"; \
		${ERROR_MSG} "\"${MAKE} NO_CHECKSUM=yes [other args]\"."; \
		exit 1;							\
	fi
	@${RM} -f ${_CKSUMFILES_INPUT}
.  else
	${RUN} set -e;							\
	case ${.TARGET:Q} in						\
	*-phase)	${TEST} ! -f ${_COOKIE.checksum} || exit 0 ;;	\
	esac;								\
	cd ${DISTDIR};							\
	if { ${_CKSUMFILES:@f@ ${ECHO} ${f};@} }			\
	    | ${_CHECKSUM_CMD} -I ${_CKSUMFILES_INPUT} ${DISTINFO_FILE:tA}; then \
		${TRUE};						\
	else								\
		${ERROR_MSG} "Make sure the Makefile and checksum file (${DISTINFO_FILE})"; \
		${ERROR_MSG} "are up to date.  If you want to override this check, type"; \
		${ERROR_MSG} "\"${MAKE} NO_CHECKSUM=yes [other args]\"."; \
		exit 1;							\
	fi
.  endif
.endif

.if !empty(TOOLS_PLATFORM.mktool)
_DISTINFO_CMD=	${TOOLS_PLATFORM.mktool} distinfo
.else
_DISTINFO_CMD=	${PKGSRC_SETENV} DIGEST=${TOOLS_DIGEST:Q} SED=${TOOLS_SED:Q} \
			TEST=${TOOLS_TEST:Q} WC=${TOOLS_WC:Q}	\
		${AWK} -f ${PKGSRCDIR}/mk/checksum/distinfo.awk --
.endif

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

_DISTINFO_ARGS_PATCHSUM+=	${PATCHDIR}/patch-*
_DISTINFO_ARGS_PATCHSUM+=	${PATCHDIR}/emul-*-patch-*

distinfo:
.  if ${USE_TMPFILES} == yes
	${_CKSUMFILES_INPUT::=${_CKSUMFILES_INPUT_cmd:sh}}
.    for file in ${_CKSUMFILES}
	@${ECHO} ${file} >> ${_CKSUMFILES_INPUT}
.    endfor
	${RUN}set -e;							\
	newfile=${DISTINFO_FILE}.$$$$;					\
	if ${_DISTINFO_CMD} ${_DISTINFO_ARGS_COMMON}			\
		-I ${_CKSUMFILES_INPUT} ${_DISTINFO_ARGS_PATCHSUM} > $$newfile; \
	then								\
		${RM} -f $$newfile;					\
		${ECHO_MSG} "=> distinfo: unchanged.";			\
	else								\
		${RM} -f ${DISTINFO_FILE};				\
		${MV} -f $$newfile ${DISTINFO_FILE};			\
	fi
	@${RM} -f ${_CKSUMFILES_INPUT}
.  else
	${RUN}set -e;							\
	newfile=${DISTINFO_FILE}.$$$$;					\
	if { ${_CKSUMFILES:@f@ ${ECHO} ${f};@} }	\
	    | ${_DISTINFO_CMD} ${_DISTINFO_ARGS_COMMON}			\
		-I ${_CKSUMFILES_INPUT} ${_DISTINFO_ARGS_PATCHSUM} > $$newfile; \
	then								\
		${RM} -f $$newfile;					\
		${ECHO_MSG} "=> distinfo: unchanged.";			\
	else								\
		${RM} -f ${DISTINFO_FILE};				\
		${MV} -f $$newfile ${DISTINFO_FILE};			\
	fi
.  endif

makesum:
.  if ${USE_TMPFILES} == yes
	${_CKSUMFILES_INPUT::=${_CKSUMFILES_INPUT_cmd:sh}}
.    for file in ${_CKSUMFILES}
	@${ECHO} ${file} >> ${_CKSUMFILES_INPUT}
.    endfor
	${RUN}set -e;							\
	newfile=${DISTINFO_FILE}.$$$$;					\
	if ${_DISTINFO_CMD} ${_DISTINFO_ARGS_COMMON}			\
		-I ${_CKSUMFILES_INPUT} > $$newfile;			\
	then								\
		${RM} -f $$newfile;					\
		${ECHO_MSG} "=> distinfo: distfiles part unchanged.";	\
	else								\
		${RM} -f ${DISTINFO_FILE};				\
		${MV} -f $$newfile ${DISTINFO_FILE};			\
	fi
	@${RM} -f ${_CKSUMFILES_INPUT}
.  else
	${RUN}set -e;							\
	newfile=${DISTINFO_FILE}.$$$$;					\
	if { ${_CKSUMFILES:@f@ ${ECHO} ${f};@} }			\
	    | ${_DISTINFO_CMD} ${_DISTINFO_ARGS_COMMON}			\
		-I ${_CKSUMFILES_INPUT} > $$newfile;			\
	then								\
		${RM} -f $$newfile;					\
		${ECHO_MSG} "=> distinfo: distfiles part unchanged.";	\
	else								\
		${RM} -f ${DISTINFO_FILE};				\
		${MV} -f $$newfile ${DISTINFO_FILE};			\
	fi
.  endif

makepatchsum:
	${RUN}set -e;							\
	newfile=${DISTINFO_FILE}.$$$$;					\
	if ${_DISTINFO_CMD} ${_DISTINFO_ARGS_COMMON}			\
		${_DISTINFO_ARGS_PATCHSUM} > $$newfile;			\
	then								\
		${RM} -f $$newfile;					\
		${ECHO_MSG} "=> distinfo: patches part unchanged.";	\
	else								\
		${RM} -f ${DISTINFO_FILE};				\
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
