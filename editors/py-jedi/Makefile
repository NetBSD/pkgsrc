# $NetBSD: Makefile,v 1.16 2024/11/11 17:00:27 wiz Exp $

DISTNAME=	jedi-0.19.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	editors python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jedi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/davidhalter/jedi
COMMENT=	Autocompletion tool for Python that can be used for text editors
LICENSE=	mit

EXTRACT_USING=	bsdtar

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-parso>=0.8.4:../../lang/py-parso
TEST_DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
TEST_DEPENDS+=	${PYPKGPREFIX}-colorama-[0-9]*:../../comms/py-colorama
TEST_DEPENDS+=	${PYPKGPREFIX}-docopt-[0-9]*:../../devel/py-docopt

USE_LANGUAGES=	# none

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
