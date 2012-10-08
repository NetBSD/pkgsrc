# $NetBSD: Makefile,v 1.15 2012/10/08 12:19:35 asau Exp $
#

DISTNAME=	xbuffy-3.4
PKGREVISION=	2
CATEGORIES=	mail x11
MASTER_SITES=	ftp://ftp.virginia.edu/pub/xbuffy/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Replacement for xbiff that handles multiple mail files

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

CPPFLAGS+=	-I${X11BASE}/include
CPPFLAGS+=	-Wall

INSTALLATION_DIRS=	lib/X11/app-defaults

post-install:
	${INSTALL_DATA} ${WRKSRC}/XBuffy.ad ${DESTDIR}${PREFIX}/lib/X11/app-defaults/XBuffy

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
