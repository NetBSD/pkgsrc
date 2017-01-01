# $NetBSD: Makefile,v 1.11 2017/01/01 14:43:43 wiz Exp $

DISTNAME=	uniconvertor-1.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	http://uniconvertor.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sk1project.org/
COMMENT=	Universal vector graphics translator
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-sk1libs-[0-9]*:../../graphics/py-sk1libs

USE_LANGUAGES=		c
PYDISTUTILSPKG=		yes
PYTHON_SELF_CONFLICT=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-sk1libs
REPLACE_PYTHON+=	src/__init__.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
