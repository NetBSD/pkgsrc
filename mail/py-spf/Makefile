# $NetBSD: Makefile,v 1.11 2020/04/17 11:27:36 adam Exp $

DISTNAME=	pyspf-2.0.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyspf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sdgathman/pyspf
COMMENT=	SPF (Sender Policy Framework) implemented in Python
LICENSE=	python-software-foundation

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-ipaddress-[0-9]*:../../net/py-ipaddress
.else
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
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
