# $NetBSD: Makefile,v 1.3 2004/07/28 02:47:34 minskim Exp $
#

DISTNAME=	advancecomp-1.10
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=advancemame/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://advancemame.sourceforge.net/
COMMENT=	Recompression utilities for .zip, .png, .mng and .gz files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c++

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
