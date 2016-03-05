# $NetBSD: Makefile,v 1.50 2016/03/05 11:27:45 jperkin Exp $

PKGREVISION= 1
.include "../../devel/libevent/Makefile.common"

PKGNAME=	libevent-${LIBEVENT_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libevent.org/
COMMENT=	Asynchronous event notification library
LICENSE=	modified-bsd

CONFLICTS+=	libev<3.9nb1

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	libevent_openssl.pc.in
PKGCONFIG_OVERRIDE+=	libevent_pthreads.pc.in
PKGCONFIG_OVERRIDE+=	libevent.pc.in
TEST_TARGET=		verify

LIBS.SunOS+=	-lnsl -lresolv
CPPFLAGS.SunOS+=	-D__EXTENSIONS__

# XXX helps build, but needs more testing
#CFLAGS.Interix+=	-Dsockaddr_storage=sockaddr_in -DNI_MAXSERV=32

.include "../../mk/bsd.prefs.mk"

# Explicitly disable epoll on illumos, provided for Linux compat only.
CONFIGURE_ENV.SunOS+=	ac_cv_func_epoll_ctl=no

.if !empty(MACHINE_PLATFORM:MHPUX-11.11-*)
CONFIGURE_ENV+=		ac_cv_func_strtoll=yes
CPPFLAGS+=		-Dstrtoll=__strtoll
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
