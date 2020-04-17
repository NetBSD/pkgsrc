# $NetBSD: Makefile,v 1.12 2020/04/17 12:02:36 adam Exp $

DISTNAME=	pyspf-2.0.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyspf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sdgathman/pyspf
COMMENT=	SPF (Sender Policy Framework) implemented in Python
LICENSE=	python-software-foundation

DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-ipaddr-[0-9]*:../../devel/py-ipaddr
.endif

USE_LANGUAGES=	# none

post-install:
.for bin in spfquery.py type99.py
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

do-test:
	cd ${WRKSRC}/test && ${PYTHONBIN} testspf.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
