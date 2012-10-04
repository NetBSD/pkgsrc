# $NetBSD: Makefile,v 1.6 2012/10/04 00:22:01 cheusov Exp $
#

DISTNAME=	tlslite-0.3.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://trevp.net/tlslite/
COMMENT=	SSL 3.0, TLS 1.0, and TLS 1.1 in Python
LICENSE=	public-domain

PKG_DESTDIR_SUPPORT=	user-destdir
PYTHON_SELF_CONFLICT=	yes

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
