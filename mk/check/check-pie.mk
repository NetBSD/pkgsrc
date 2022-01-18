# $NetBSD
#
# This file verifies that MKPIE (position-independent executables) was applied
# accordingly at build-time.
#
# User-settable variables:
#
# CHECK_PIE
#	Whether the check should be enabled or not.
#
#	Default value: "yes" for PKG_DEVELOPERs, "no" otherwise.
#
# Package-settable variables:
#
# CHECK_PIE_SKIP
#	A list of shell patterns (like man/*) that should be excluded
#	from the check. Note that a * in a pattern also matches a slash
#	in a pathname.
#
#	Default value: empty.
#
# CHECK_PIE_SUPPORTED
#	Whether the check should be enabled for this package or not.
#
#	Default value: yes
#

_VARGROUPS+=		check-pie
_USER_VARS.check-pie=	CHECK_PIE
_PKG_VARS.check-pie=	CHECK_PIE_SUPPORTED

.if ${_PKGSRC_MKPIE:Uno} != "no" && ${PKG_DEVELOPER:Uno:tl} != "no"
CHECK_PIE?=		yes
.else
CHECK_PIE?=		no
.endif
CHECK_PIE_SUPPORTED?=	yes
CHECK_PIE_SKIP?=	# none

# All binaries but not libraries
_CHECK_PIE_ERE=		(bin/|sbin/|libexec/)

_CHECK_PIE_FILELIST_CMD?=					\
	${SED} -e '/^@/d' ${PLIST} |				\
	while read file; do					\
		${TEST} -h "$$file" || ${ECHO} "$$file";	\
	done

_CHECK_PIE_CMD=		# empty
.if ${OBJECT_FMT} == "ELF"
USE_TOOLS+=		awk readelf
_CHECK_PIE_CMD=		${AWK} -f ${PKGSRCDIR}/mk/check/check-pie-elf.awk
_CHECK_PIE_ENV+=	READELF=${TOOLS_PATH.readelf:Q}
.endif

.if	${CHECK_PIE:tl} == "yes" && \
	${CHECK_PIE_SUPPORTED:tl} == "yes" && \
	!empty(_CHECK_PIE_CMD)
privileged-install-hook: _check-pie
_check-pie: error-check .PHONY
	@${STEP_MSG} "Checking for PIE in ${PKGNAME}"
	${RUN} rm -f ${ERROR_DIR}/${.TARGET}
	${RUN}								\
		cd ${DESTDIR:Q}${PREFIX:Q};				\
		${_CHECK_PIE_FILELIST_CMD} |				\
		${EGREP} -h ${_CHECK_PIE_ERE:Q} |			\
		while read file; do					\
			case "$$file" in				\
				${CHECK_PIE_SKIP:@p@${p}) continue;;@}	\
				*) ${ECHO} "$$file";			\
			esac;						\
		done |							\
		${PKGSRC_SETENV} ${_CHECK_PIE_ENV} ${_CHECK_PIE_CMD}	\
			> ${ERROR_DIR}/${.TARGET}
.endif
