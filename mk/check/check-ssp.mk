# $NetBSD: check-ssp.mk,v 1.2 2020/03/23 09:24:35 jperkin Exp $
#
# This file verifies that SSP was applied accordingly at build-time.
#
# User-settable variables:
#
# CHECK_SSP
#	Whether the check should be enabled or not.
#
#	Default value: "yes" for PKG_DEVELOPERs, "no" otherwise.
#
# Package-settable variables:
#
# CHECK_SSP_SKIP
#	A list of shell patterns (like man/*) that should be excluded
#	from the check. Note that a * in a pattern also matches a slash
#	in a pathname.
#
#	Default value: empty.
#
# CHECK_SSP_SUPPORTED
#	Whether the check should be enabled for this package or not.
#
#	Default value: yes
#

_VARGROUPS+=			check-ssp
_USER_VARS.check-ssp=		CHECK_SSP
_PKG_VARS.check-ssp=		CHECK_SSP_SUPPORTED

.if ${_PKGSRC_USE_SSP:Uno} != "no" && \
    ${PKG_DEVELOPER:Uno} != "no"
CHECK_SSP?=			yes
.else
CHECK_SSP?=			no
.endif
CHECK_SSP_SUPPORTED?=		yes
CHECK_SSP_SKIP?=		# none

# All binaries and shared libraries.
_CHECK_SSP_ERE=		(bin/|sbin/|libexec/|\.so$$|lib/lib.*\.so)

_CHECK_SSP_FILELIST_CMD?=	${SED} -e '/^@/d' ${PLIST} |		\
	(while read file; do						\
		${TEST} -h "$$file" || ${ECHO} "$$file";		\
	done)

.if !empty(CHECK_SSP:M[Yy][Ee][Ss]) && \
    !empty(CHECK_SSP_SUPPORTED:M[Yy][Ee][Ss]) && \
    ${_USE_CHECK_SSP_NATIVE} == "yes"
CHECK_SSP_NATIVE_ENV=
.  if ${OBJECT_FMT} == "ELF"
USE_TOOLS+=		readelf
CHECK_SSP_NATIVE=	${PKGSRCDIR}/mk/check/check-ssp-elf.awk
CHECK_SSP_NATIVE_ENV+=	PLATFORM_RPATH=${_OPSYS_SYSTEM_RPATH:Q}
CHECK_SSP_NATIVE_ENV+=	READELF=${TOOLS_PATH.readelf:Q}
.  endif
CHECK_SSP_NATIVE_ENV+=	CROSS_DESTDIR=${_CROSS_DESTDIR:Q}
CHECK_SSP_NATIVE_ENV+=	PKG_INFO_CMD=${PKG_INFO:Q}
CHECK_SSP_NATIVE_ENV+=	DEPENDS_FILE=${_RRDEPENDS_FILE:Q}
CHECK_SSP_NATIVE_ENV+=	DESTDIR=${DESTDIR:Q}
CHECK_SSP_NATIVE_ENV+=	WRKDIR=${WRKDIR:Q}
.  if defined(CHECK_WRKREF) && !empty(CHECK_WRKREF:Mextra)
CHECK_SSP_NATIVE_ENV+=	CHECK_WRKREF_EXTRA_DIRS=${CHECK_WRKREF_EXTRA_DIRS:Q}
.  endif

privileged-install-hook: _check-ssp
_check-ssp: error-check .PHONY
	@${STEP_MSG} "Checking for SSP in ${PKGNAME}"
	${RUN} rm -f ${ERROR_DIR}/${.TARGET}
	${RUN}							\
	cd ${DESTDIR:Q}${PREFIX:Q};				\
	${_CHECK_SSP_FILELIST_CMD} |				\
	${EGREP} -h ${_CHECK_SSP_ERE:Q} |			\
	while read file; do					\
		case "$$file" in				\
		${CHECK_SSP_SKIP:@p@${p}) continue ;;@}		\
		*) ;;						\
		esac;						\
		${ECHO} $$file;					\
	done |							\
	${PKGSRC_SETENV} ${CHECK_SSP_NATIVE_ENV} ${AWK} -f ${CHECK_SSP_NATIVE} > ${ERROR_DIR}/${.TARGET}
.endif
