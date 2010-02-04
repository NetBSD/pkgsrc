# $NetBSD: Makefile,v 1.14 2010/02/04 14:25:56 joerg Exp $
#

DISTNAME=	xbuffy-3.4
PKGREVISION=	2
CATEGORIES=	mail x11
MASTER_SITES=	ftp://ftp.virginia.edu/pub/xbuffy/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Replacement for xbiff that handles multiple mail files

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

CPPFLAGS+=	-I${X11BASE}/include
CPPFLAGS+=	-Wall

INSTALLATION_DIRS=	lib/X11/app-defaults

post-install:
	${INSTALL_DATA} ${WRKSRC}/XBuffy.ad ${DESTDIR}${PREFIX}/lib/X11/app-defaults/XBuffy

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
