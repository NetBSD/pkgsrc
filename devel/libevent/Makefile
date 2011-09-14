# $NetBSD: Makefile,v 1.38 2011/09/14 16:33:45 hans Exp $
#

DISTNAME=	libevent-2.0.10-stable
PKGNAME=	${DISTNAME:S/-stable//}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://monkey.org/~provos/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://monkey.org/~provos/libevent/
COMMENT=	Asynchronous event notification library
LICENSE=	modified-bsd

CONFLICTS+=	libev<3.9nb1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
TEST_TARGET=	verify
PKG_DESTDIR_SUPPORT=	user-destdir

LIBS.SunOS+=	-lnsl -lresolv
CPPFLAGS.SunOS+=	-D__EXTENSIONS__

PKGCONFIG_OVERRIDE+=	libevent_openssl.pc.in
PKGCONFIG_OVERRIDE+=	libevent_pthreads.pc.in
PKGCONFIG_OVERRIDE+=	libevent.pc.in

REPLACE_PYTHON=		event_rpcgen.py

# XXX helps build, but needs more testing
#CFLAGS.Interix+=	-Dsockaddr_storage=sockaddr_in -DNI_MAXSERV=32

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MHPUX-11.11-*)
CONFIGURE_ENV+=		ac_cv_func_strtoll=yes
CPPFLAGS+=		-Dstrtoll=__strtoll
.endif

.include "../../lang/python/application.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
