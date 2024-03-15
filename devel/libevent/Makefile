# $NetBSD: Makefile,v 1.59 2024/03/15 18:07:32 nia Exp $

PKGREVISION= 2
.include "../../devel/libevent/Makefile.common"

PKGNAME=	${DISTNAME:S/-stable//}
COMMENT=	Asynchronous event notification library

CONFLICTS+=	libev<3.9nb1

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	libevent_core.pc.in
PKGCONFIG_OVERRIDE+=	libevent_extra.pc.in
PKGCONFIG_OVERRIDE+=	libevent_openssl.pc.in
PKGCONFIG_OVERRIDE+=	libevent_pthreads.pc.in
PKGCONFIG_OVERRIDE+=	libevent.pc.in
TEST_TARGET=		verify

LIBS.SunOS+=		-lnsl -lresolv
CPPFLAGS.SunOS+=	-D__EXTENSIONS__
CPPFLAGS.QNX+=		-D__EXT_POSIX2

.include "../../mk/bsd.prefs.mk"

# Explicitly disable epoll on illumos & NetBSD, provided for Linux compat only.
CONFIGURE_ENV.SunOS+=	ac_cv_func_epoll_ctl=no
CONFIGURE_ENV.NetBSD+=	ac_cv_func_epoll_ctl=no

# www/links fails to run on old versions of Darwin without this change.
.if ${OPSYS} == "Darwin" && ${OPSYS_VERSION} < 100500
CONFIGURE_ENV+=		ac_cv_func_kqueue=no
CONFIGURE_ENV+=		ac_cv_func_poll=no
.endif

.if !empty(MACHINE_PLATFORM:MHPUX-11.11-*)
CONFIGURE_ENV+=		ac_cv_func_strtoll=yes
CPPFLAGS+=		-Dstrtoll=__strtoll
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
