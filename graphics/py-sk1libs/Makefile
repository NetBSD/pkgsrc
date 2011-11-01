# $NetBSD: Makefile,v 1.3 2011/11/01 06:01:44 sbd Exp $

DISTNAME=	sk1libs-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	http://uniconvertor.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sk1project.org/
COMMENT=	Set of python non-GUI extensions for sK1 Project
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED=	27 26 25
USE_LANGUAGES=		c
PYDISTUTILSPKG=		yes

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
