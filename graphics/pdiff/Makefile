# $NetBSD: Makefile,v 1.16 2013/03/02 10:44:35 tron Exp $
#

DISTNAME=		PerceptualDiff-1.0.1
PKGNAME=		pdiff-1.0.1
PKGREVISION=		7
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pdiff/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pdiff.sourceforge.net/
COMMENT=		Image comparison through perceptually based image metric

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
USE_CMAKE=		yes

# not compatible with png>=1.4
#.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
