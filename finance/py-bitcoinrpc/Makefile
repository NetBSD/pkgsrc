# $NetBSD: Makefile,v 1.1 2019/12/03 16:32:16 adam Exp $

DISTNAME=	python-bitcoinrpc-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-bitcoinrpc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jgarzik/python-bitcoinrpc
COMMENT=	Enhanced version of python-jsonrpc for use with Bitcoin
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
