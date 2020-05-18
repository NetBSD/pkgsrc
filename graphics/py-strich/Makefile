# $NetBSD: Makefile,v 1.3 2020/05/18 10:30:16 adam Exp $

DISTNAME=	pyStrich-0.8
PKGNAME=	${PYPKGPREFIX}-strich-0.8
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyStrich/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mmulqueen/pyStrich
COMMENT=	1D and 2D barcode generator
LICENSE=	2-clause-bsd AND apache-2.0

DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow

PYTHON_VERSIONED_DEPENDENCIES=	test:test

do-test:
	${MKDIR} ${WRKSRC}/pystrich/code128/test_img ${WRKSRC}/pystrich/ean13/test_img
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
