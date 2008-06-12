# $NetBSD: Makefile,v 1.3 2008/06/12 02:14:45 joerg Exp $
#

DISTNAME=	tlslite-0.3.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://trevp.net/tlslite/
COMMENT=	SSL 3.0, TLS 1.0, and TLS 1.1 in Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
