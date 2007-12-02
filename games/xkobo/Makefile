# $NetBSD: Makefile,v 1.20 2007/12/02 00:02:42 wiz Exp $

DISTNAME=	xkobo-1.11
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=games/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://seki.math.hokudai.ac.jp:20080/xkobo-current.html
COMMENT=	Multi-way scrolling shoot 'em up game for X.  Strangely addictive

USE_IMAKE=	yes
USE_LANGUAGES=	c c++
BUILD_TARGET+=	xkobo all

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
