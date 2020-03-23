# $NetBSD: check-shlibs.mk,v 1.32 2020/03/23 09:24:35 jperkin Exp $
#
# This file verifies that all libraries used by the package can be found
# at run-time.
#
# User-settable variables:
#
# CHECK_SHLIBS
#	Whether the check should be enabled or not.
#
#	Default value: "yes" for PKG_DEVELOPERs, "no" otherwise.
#
# CHECK_SHLIBS_BLACKLIST
# 	A list of regular expressions that will cause the test to fail
# 	if they are matched in the resolved runpath.  For example, set
# 	to ^/usr/lib/lib(crypto|ssl) will ensure that OpenSSL is not
# 	accidentally picked up from the OS.
#
#	Default value: empty.
#
# Package-settable variables:
#
# CHECK_SHLIBS_SKIP
#	A list of shell patterns (like man/*) that should be excluded
#	from the check. Note that a * in a pattern also matches a slash
#	in a pathname.
#
#	Default value: empty.
#
# CHECK_SHLIBS_SUPPORTED
#	Whether the check should be enabled for this package or not.
#
#	Default value: yes
#

_VARGROUPS+=			check-shlibs
_USER_VARS.check-shlibs=	CHECK_SHLIBS
_PKG_VARS.check-shlibs=		CHECK_SHLIBS_SUPPORTED

.if ${PKG_DEVELOPER:Uno} != "no"
CHECK_SHLIBS?=			yes
.else
CHECK_SHLIBS?=			no
.endif
CHECK_SHLIBS_SUPPORTED?=	yes
CHECK_SHLIBS_SKIP?=		# none

# All binaries and shared libraries.
_CHECK_SHLIBS_ERE=	(bin/|sbin/|libexec/|\.(dylib|sl|so)$$|lib/lib.*\.(dylib|sl|so))

_CHECK_SHLIBS_FILELIST_CMD?=	${SED} -e '/^@/d' ${PLIST} |		\
	(while read file; do						\
		${TEST} -h "$$file" || ${ECHO} "$$file";		\
	done)

.if !empty(CHECK_SHLIBS:M[Yy][Ee][Ss]) && \
    !empty(CHECK_SHLIBS_SUPPORTED:M[Yy][Ee][Ss]) && \
    ${_USE_CHECK_SHLIBS_NATIVE} == "yes"
CHECK_SHLIBS_NATIVE_ENV=
.  if ${OBJECT_FMT} == "ELF"
USE_TOOLS+=			readelf
CHECK_SHLIBS_NATIVE=		${PKGSRCDIR}/mk/check/check-shlibs-elf.awk
CHECK_SHLIBS_NATIVE_ENV+=	PLATFORM_RPATH=${_OPSYS_SYSTEM_RPATH:Q}
CHECK_SHLIBS_NATIVE_ENV+=	READELF=${TOOLS_PATH.readelf:Q}
.  elif ${OBJECT_FMT} == "Mach-O"
CHECK_SHLIBS_NATIVE=		${PKGSRCDIR}/mk/check/check-shlibs-macho.awk
.  endif
CHECK_SHLIBS_NATIVE_ENV+=	CROSS_DESTDIR=${_CROSS_DESTDIR:Q}
CHECK_SHLIBS_NATIVE_ENV+=	PKG_INFO_CMD=${PKG_INFO:Q}
CHECK_SHLIBS_NATIVE_ENV+=	DEPENDS_FILE=${_RRDEPENDS_FILE:Q}
CHECK_SHLIBS_NATIVE_ENV+=	DESTDIR=${DESTDIR:Q}
CHECK_SHLIBS_NATIVE_ENV+=	WRKDIR=${WRKDIR:Q}
CHECK_SHLIBS_NATIVE_ENV+=	LANG=C
.  if defined(CHECK_WRKREF) && !empty(CHECK_WRKREF:Mextra)
CHECK_SHLIBS_NATIVE_ENV+=	CHECK_WRKREF_EXTRA_DIRS=${CHECK_WRKREF_EXTRA_DIRS:Q}
.  endif
.  if defined(CHECK_SHLIBS_BLACKLIST)
CHECK_SHLIBS_NATIVE_ENV+=	CHECK_SHLIBS_BLACKLIST=${CHECK_SHLIBS_BLACKLIST:Q}
.  endif

privileged-install-hook: _check-shlibs
_check-shlibs: error-check .PHONY
	@${STEP_MSG} "Checking for missing run-time search paths in ${PKGNAME}"
	${RUN} rm -f ${ERROR_DIR}/${.TARGET}
	${RUN}					\
	cd ${DESTDIR:Q}${PREFIX:Q};					\
	${_CHECK_SHLIBS_FILELIST_CMD} |					\
	${EGREP} -h ${_CHECK_SHLIBS_ERE:Q} |				\
	while read file; do						\
		case "$$file" in					\
		${CHECK_SHLIBS_SKIP:@p@${p}) continue ;;@}		\
		*) ;;							\
		esac;							\
		${ECHO} $$file;						\
	done |								\
	${PKGSRC_SETENV} ${CHECK_SHLIBS_NATIVE_ENV} ${AWK} -f ${CHECK_SHLIBS_NATIVE} > ${ERROR_DIR}/${.TARGET}
.endif
