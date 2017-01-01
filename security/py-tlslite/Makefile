# $NetBSD: Makefile,v 1.14 2017/01/01 22:01:45 schmonz Exp $

DISTNAME=		tlslite-0.4.8
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		security python
MASTER_SITES=		${MASTER_SITE_GITHUB:=trevp/}

GITHUB_PROJECT=		tlslite
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://trevp.net/tlslite/
COMMENT=		SSL 3.0, TLS 1.0, and TLS 1.1 in Python
LICENSE=		public-domain

USE_LANGUAGES=		# none

post-extract:
	mv ${WRKSRC}/scripts/tls.py ${WRKSRC}/scripts/tls${PYVERSSUFFIX}.py
	mv ${WRKSRC}/scripts/tlsdb.py ${WRKSRC}/scripts/tlsdb${PYVERSSUFFIX}.py

REPLACE_PYTHON=		setup.py tests/httpsclient.py tests/tlstest.py

SUBST_CLASSES+=		pyclash
SUBST_STAGE.pyclash=	do-configure
SUBST_FILES.pyclash=	setup.py tests/tlstest.py tests/httpsserver.sh
SUBST_SED.pyclash=	-e 's|@PYTHONBIN@|${PYTHONBIN}|g'
SUBST_SED.pyclash+=	-e 's|@PYVERSSUFFIX@|${PYVERSSUFFIX}|g'

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
