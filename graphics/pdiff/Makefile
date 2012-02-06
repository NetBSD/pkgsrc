# $NetBSD: Makefile,v 1.12 2012/02/06 12:40:32 wiz Exp $
#

DISTNAME=		PerceptualDiff-1.0.1
PKGNAME=		pdiff-1.0.1
PKGREVISION=		5
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pdiff/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://pdiff.sourceforge.net/
COMMENT=		Image comparison through perceptually based image metric

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_CMAKE=		yes

# not compatible with png>=1.4
#.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
