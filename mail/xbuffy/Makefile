# $NetBSD: Makefile,v 1.16 2015/07/04 16:18:37 joerg Exp $
#

DISTNAME=	xbuffy-3.4
PKGREVISION=	2
CATEGORIES=	mail x11
MASTER_SITES=	ftp://ftp.virginia.edu/pub/xbuffy/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Replacement for xbiff that handles multiple mail files

GNU_CONFIGURE=	YES

CPPFLAGS+=	-I${X11BASE}/include
CPPFLAGS+=	-Wall

INSTALLATION_DIRS=	lib/X11/app-defaults

post-install:
	${INSTALL_DATA} ${WRKSRC}/XBuffy.ad ${DESTDIR}${PREFIX}/lib/X11/app-defaults/XBuffy

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
