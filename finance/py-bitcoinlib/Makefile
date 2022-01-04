# $NetBSD: Makefile,v 1.3 2022/01/04 20:53:52 wiz Exp $

DISTNAME=	python-bitcoinlib-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
PKGREVISION=	1
CATEGORIES=	finance net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-bitcoinlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/petertodd/python-bitcoinlib
COMMENT=	Python bitcoin library
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
