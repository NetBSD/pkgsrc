# $NetBSD: Makefile,v 1.21 2010/02/14 22:06:02 joerg Exp $
#

DISTNAME=		xjig-2.4
PKGREVISION=		3
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Jigsaw puzzle

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=		yes
USE_LANGUAGES=		c c++

BUILD_TARGET=		xjig all

INSTALLATION_DIRS+=	lib/xjig

post-install:
	${INSTALL_DATA} ${WRKSRC}/tina.gif ${DESTDIR}${PREFIX}/lib/xjig

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
