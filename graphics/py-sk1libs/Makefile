# $NetBSD: Makefile,v 1.22 2023/11/12 13:22:14 wiz Exp $

DISTNAME=	sk1libs-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	graphics python
MASTER_SITES=	http://uniconvertor.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sk1project.net/
COMMENT=	Set of python non-GUI extensions for sK1 Project
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.9.1

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
