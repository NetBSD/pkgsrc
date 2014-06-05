# $NetBSD: Makefile,v 1.5 2014/06/05 19:48:33 tron Exp $

DISTNAME=	libexecinfo-1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_FREEBSD}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ober@NetBSD.org
HOMEPAGE=       http://www.freebsdsoftware.org/devel/libexecinfo.html
COMMENT=	BSD Licensed clone of backtrace facility found in GNU libc
LICENSE=	2-clause-bsd

USE_BSD_MAKEFILE=	yes
MAKE_FLAGS+=	MKLINT=no

CFLAGS.Linux+=	-D_GNU_SOURCE # Dl_info internals
CFLAGS.Linux+=	-Wno-unused-result # write(2) is declared specially

INSTALLATION_DIRS=	include lib

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	mkpic
.if empty(MACHINE_PLATFORM:MSunOS-5.10-*)
PLIST.mkpic=	yes
.else
MAKE_ENV+=	MKPIC=no
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/execinfo.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
