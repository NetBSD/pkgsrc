# $NetBSD: Makefile,v 1.18 2020/01/18 23:32:16 rillig Exp $
#

DISTNAME=		PerceptualDiff-1.0.1
PKGNAME=		pdiff-1.0.1
PKGREVISION=		7
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pdiff/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://pdiff.sourceforge.net/
COMMENT=		Image comparison through perceptually based image metric

USE_LANGUAGES=		c c++
USE_CMAKE=		yes

# not compatible with png>=1.4
#.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
