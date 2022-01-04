# $NetBSD: Makefile,v 1.5 2022/01/04 20:54:07 wiz Exp $

DISTNAME=	pyStrich-0.8
PKGNAME=	${PYPKGPREFIX}-strich-0.8
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyStrich/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mmulqueen/pyStrich
COMMENT=	1D and 2D barcode generator
LICENSE=	2-clause-bsd AND apache-2.0

PYTHON_VERSIONED_DEPENDENCIES=	Pillow test:test

do-test:
	${MKDIR} ${WRKSRC}/pystrich/code128/test_img ${WRKSRC}/pystrich/ean13/test_img
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
