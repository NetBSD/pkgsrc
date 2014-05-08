# $NetBSD: Makefile,v 1.1 2014/05/08 10:14:10 rodent Exp $
#

DISTNAME=	v0.1
PKG=		python-bitcoinlib-${DISTNAME:S/v//1}
PKGNAME=	${PYPKGPREFIX}-${PKG}
CATEGORIES=	finance net python
MASTER_SITES=	https://github.com/petertodd/python-bitcoinlib/archive/
DIST_SUBDIR=	${PKGBASE:S/${PYPKGPREFIX}/py/1}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/petertodd/python-bitcoinlib
COMMENT=	Python bitcoin library
LICENSE=	gnu-lgpl-v2.1 AND mit

WRKSRC=		${WRKDIR}/${PKG}
USE_LANGUAGES=	# none

EGG_NAME=	${PKG:S/-/_/1}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
