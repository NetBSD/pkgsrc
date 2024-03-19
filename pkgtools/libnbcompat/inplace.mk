# $NetBSD: inplace.mk,v 1.18 2024/03/19 23:18:21 nia Exp $
#
# This file should not be included directly. Use USE_FEATURES instead.
#
# This Makefile fragment builds a working copy of libnbcompat inside
# ${WRKDIR}.
#

.include "../../mk/bsd.prefs.mk"

LIBNBCOMPAT_FILESDIR=	${.CURDIR}/../../pkgtools/libnbcompat/files
LIBNBCOMPAT_SRCDIR=	${WRKDIR}/libnbcompat

# Prevent libnbcompat from being embedded as a dependency in the libtool
# archive.
.if !empty(USE_LIBTOOL:tl:Myes)
LIBNBCOMPAT_LIBNAME=	${LIBNBCOMPAT_SRCDIR}/libnbcompat.a
.else
LIBNBCOMPAT_LIBNAME=	-lnbcompat
.endif

CPPFLAGS.nbcompat=	-DHAVE_NBCOMPAT_H=1 -I${LIBNBCOMPAT_SRCDIR}
LDFLAGS.nbcompat=	-L${LIBNBCOMPAT_SRCDIR}
LDADD.nbcompat=		${LIBNBCOMPAT_LIBNAME}

post-extract: libnbcompat-extract
.PHONY: libnbcompat-extract
libnbcompat-extract:
	${RUN} ${CP} -R ${LIBNBCOMPAT_FILESDIR} ${LIBNBCOMPAT_SRCDIR}
	${RM} -f ${LIBNBCOMPAT_SRCDIR}/config.guess ${LIBNBCOMPAT_SRCDIR}/config.sub
	${LN} -fs ${PKGSRCDIR}/mk/gnu-config/config.guess ${LIBNBCOMPAT_SRCDIR}/config.guess
	${LN} -fs ${PKGSRCDIR}/mk/gnu-config/config.sub ${LIBNBCOMPAT_SRCDIR}/config.sub

.if ${USE_CROSS_COMPILE:U:tl} == "yes"
NBCOMPAT_CONFIGURE_ARGS+=	--build=${NATIVE_MACHINE_GNU_PLATFORM:Q}
.endif
NBCOMPAT_CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM:Q}

# The illumos fts(3) implementation is not (as of August 2018) largefile aware
CONFIGURE_ENV.SunOS+=	ac_cv_func_fts_open=no

# NetBSD has working printf %lld and correct vsnprintf return values,
# which can only be detected by runtime tests, not permitted when
# cross-compiling.
.if ${USE_CROSS_COMPILE:U:tl} == "yes"
CONFIGURE_ENV.NetBSD+=	nb_cv_printf_lld=yes
CONFIGURE_ENV.NetBSD+=	nb_cv_std_vsnprintf=yes
.endif

pre-configure: libnbcompat-build
.PHONY: libnbcompat-build
libnbcompat-build:
	@${STEP_MSG} "Configuring and building libnbcompat"
	${RUN} ${_ULIMIT_CMD}						\
	cd ${LIBNBCOMPAT_SRCDIR} && ${SETENV}				\
		AWK=${AWK:Q} CC=${CC:Q} CFLAGS=${CFLAGS:M*:Q}		\
		CPPFLAGS=${CPPFLAGS:M*:Q}				\
		${CONFIGURE_ENV:S,${LIBNBCOMPAT_LIBNAME},,g}		\
		${CONFIG_SHELL}						\
		${CONFIGURE_SCRIPT} ${NBCOMPAT_CONFIGURE_ARGS} &&	\
		${SETENV} ${MAKE_ENV:S,${LIBNBCOMPAT_LIBNAME},,g}	\
		${MAKE} -j${MAKE_JOBS:U1:Q}
