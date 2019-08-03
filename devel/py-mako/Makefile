# $NetBSD: Makefile,v 1.17 2019/08/03 11:27:27 adam Exp $

DISTNAME=	Mako-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Mako/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.makotemplates.org/
COMMENT=	Hyperfast and lightweight templating for the Python platform
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.1.0:../../devel/py-test

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} mako-render mako-render-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
