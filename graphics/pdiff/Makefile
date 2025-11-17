# $NetBSD: Makefile,v 1.25 2025/11/17 11:00:58 wiz Exp $

DISTNAME=		PerceptualDiff-1.0.1
PKGNAME=		pdiff-1.0.1
PKGREVISION=		11
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pdiff/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://pdiff.sourceforge.net/
COMMENT=		Image comparison through perceptually based image metric

USE_LANGUAGES=		c c++

.include "../../devel/cmake/build.mk"
# not compatible with png>=1.4
#.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
