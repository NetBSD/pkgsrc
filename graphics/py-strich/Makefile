# $NetBSD: Makefile,v 1.2 2017/10/23 13:42:17 wiz Exp $

DISTNAME=	pyStrich-0.8
PKGNAME=	${PYPKGPREFIX}-strich-0.8
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyStrich/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mmulqueen/pyStrich
COMMENT=	1D and 2D barcode generator
LICENSE=	2-clause-bsd AND apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=2.8:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow

do-test:
	${MKDIR} ${WRKSRC}/pystrich/code128/test_img ${WRKSRC}/pystrich/ean13/test_img
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
