# $NetBSD: Makefile,v 1.34 2009/08/18 16:53:14 drochner Exp $
#

DISTNAME=	libevent-1.4.12-stable
PKGNAME=	${DISTNAME:S/-stable//}
CATEGORIES=	devel
MASTER_SITES=	http://monkey.org/~provos/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://monkey.org/~provos/libevent/
COMMENT=	Asynchronous event notification library

CONFLICTS+=	libev-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
TEST_TARGET=	verify
PKG_DESTDIR_SUPPORT=	user-destdir

LIBS.SunOS+=	-lnsl -lresolv

# XXX helps build, but needs more testing
#CFLAGS.Interix+=	-Dsockaddr_storage=sockaddr_in -DNI_MAXSERV=32

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MHPUX-11.11-*)
CONFIGURE_ENV+=		ac_cv_func_strtoll=yes
CPPFLAGS+=		-Dstrtoll=__strtoll
.endif

.include "../../mk/bsd.pkg.mk"
