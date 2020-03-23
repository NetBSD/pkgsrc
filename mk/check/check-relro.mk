# $NetBSD: check-relro.mk,v 1.4 2020/03/23 09:24:35 jperkin Exp $
#
# This file verifies that RELRO (read-only relocations) was applied
# accordingly at build-time.
#
# User-settable variables:
#
# CHECK_RELRO
#	Whether the check should be enabled or not.
#
#	Default value: "yes" for PKG_DEVELOPERs, "no" otherwise.
#
# Package-settable variables:
#
# CHECK_RELRO_SKIP
#	A list of shell patterns (like man/*) that should be excluded
#	from the check. Note that a * in a pattern also matches a slash
#	in a pathname.
#
#	Default value: empty.
#
# CHECK_RELRO_SUPPORTED
#	Whether the check should be enabled for this package or not.
#
#	Default value: yes
#

_VARGROUPS+=			check-relro
_USER_VARS.check-relro=		CHECK_RELRO
_PKG_VARS.check-relro=		CHECK_RELRO_SUPPORTED

.if ${PKGSRC_USE_RELRO:Uno} != "no" && \
    ${PKG_DEVELOPER:Uno} != "no"
CHECK_RELRO?=			yes
.else
CHECK_RELRO?=			no
.endif
CHECK_RELRO_SUPPORTED?=	yes
CHECK_RELRO_SKIP?=		# none

# All binaries and shared libraries.
_CHECK_RELRO_ERE=		(bin/|sbin/|libexec/|\.so$$|lib/lib.*\.so)

_CHECK_RELRO_FILELIST_CMD?=	${SED} -e '/^@/d' ${PLIST} |		\
	(while read file; do						\
		${TEST} -h "$$file" || ${ECHO} "$$file";		\
	done)

.if !empty(CHECK_RELRO:M[Yy][Ee][Ss]) && \
    !empty(CHECK_RELRO_SUPPORTED:M[Yy][Ee][Ss]) && \
    ${_USE_CHECK_RELRO_NATIVE} == "yes"
CHECK_RELRO_NATIVE_ENV=
.  if ${OBJECT_FMT} == "ELF"
USE_TOOLS+=			readelf
CHECK_RELRO_NATIVE=		${PKGSRCDIR}/mk/check/check-relro-elf.awk
CHECK_RELRO_NATIVE_ENV+=	PLATFORM_RPATH=${_OPSYS_SYSTEM_RPATH:Q}
CHECK_RELRO_NATIVE_ENV+=	READELF=${TOOLS_PATH.readelf:Q}
.  endif
CHECK_RELRO_NATIVE_ENV+=	CROSS_DESTDIR=${_CROSS_DESTDIR:Q}
CHECK_RELRO_NATIVE_ENV+=	PKG_INFO_CMD=${PKG_INFO:Q}
CHECK_RELRO_NATIVE_ENV+=	DEPENDS_FILE=${_RRDEPENDS_FILE:Q}
CHECK_RELRO_NATIVE_ENV+=	DESTDIR=${DESTDIR:Q}
CHECK_RELRO_NATIVE_ENV+=	WRKDIR=${WRKDIR:Q}
.  if defined(CHECK_WRKREF) && !empty(CHECK_WRKREF:Mextra)
CHECK_RELRO_NATIVE_ENV+=	CHECK_WRKREF_EXTRA_DIRS=${CHECK_WRKREF_EXTRA_DIRS:Q}
.  endif

privileged-install-hook: _check-relro
_check-relro: error-check .PHONY
	@${STEP_MSG} "Checking for RELRO in ${PKGNAME}"
	${RUN} rm -f ${ERROR_DIR}/${.TARGET}
	${RUN}					\
	cd ${DESTDIR:Q}${PREFIX:Q};					\
	${_CHECK_RELRO_FILELIST_CMD} |					\
	${EGREP} -h ${_CHECK_RELRO_ERE:Q} |				\
	while read file; do						\
		case "$$file" in					\
		${CHECK_RELRO_SKIP:@p@${p}) continue ;;@}		\
		*) ;;							\
		esac;							\
		${ECHO} $$file;						\
	done |								\
	${PKGSRC_SETENV} ${CHECK_RELRO_NATIVE_ENV} ${AWK} -f ${CHECK_RELRO_NATIVE} > ${ERROR_DIR}/${.TARGET}
.endif
