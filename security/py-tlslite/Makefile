# $NetBSD: Makefile,v 1.12 2017/01/01 14:43:56 wiz Exp $

DISTNAME=	tlslite-0.3.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://trevp.net/tlslite/
COMMENT=	SSL 3.0, TLS 1.0, and TLS 1.1 in Python
LICENSE=	public-domain

PYTHON_SELF_CONFLICT=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.3.8

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
