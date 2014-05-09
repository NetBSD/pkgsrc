# $NetBSD: Makefile,v 1.10 2014/05/09 07:37:08 wiz Exp $

DISTNAME=	sk1libs-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	graphics python
MASTER_SITES=	http://uniconvertor.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sk1project.org/
COMMENT=	Set of python non-GUI extensions for sK1 Project
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.9.1

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
