# $NetBSD: Makefile,v 1.23 2012/10/23 10:24:05 wiz Exp $
#

DISTNAME=		xjig-2.4
PKGREVISION=		3
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Jigsaw puzzle

USE_IMAKE=		yes
USE_LANGUAGES=		c c++

BUILD_TARGET=		xjig all

INSTALLATION_DIRS+=	lib/xjig

post-install:
	${INSTALL_DATA} ${WRKSRC}/tina.gif ${DESTDIR}${PREFIX}/lib/xjig

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
