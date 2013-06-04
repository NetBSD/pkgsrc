# $NetBSD: Makefile,v 1.8 2013/06/04 22:16:26 tron Exp $

DISTNAME=	sk1libs-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	graphics python
MASTER_SITES=	http://uniconvertor.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sk1project.org/
COMMENT=	Set of python non-GUI extensions for sK1 Project
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c
PYDISTUTILSPKG=		yes

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
