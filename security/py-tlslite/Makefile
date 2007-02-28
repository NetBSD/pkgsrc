# $NetBSD: Makefile,v 1.1.1.1 2007/02/28 05:34:25 schmonz Exp $
#

DISTNAME=	tlslite-0.3.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://trevp.net/tlslite/
COMMENT=	SSL 3.0, TLS 1.0, and TLS 1.1 in Python

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED?=	24 23 22

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
