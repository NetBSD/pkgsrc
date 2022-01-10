# $NetBSD: Makefile,v 1.2 2022/01/10 08:50:02 wiz Exp $

DISTNAME=	python-bitcoinrpc-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
PKGREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-bitcoinrpc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jgarzik/python-bitcoinrpc
COMMENT=	Enhanced version of python-jsonrpc for use with Bitcoin
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
