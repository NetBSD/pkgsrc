# $NetBSD: Makefile,v 1.7 2022/01/04 20:54:24 wiz Exp $

DISTNAME=	PySocks-1.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PySocks/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Anorov/PySocks
COMMENT=	Python SOCKS client module
LICENSE=	modified-bsd

CONFLICTS=	${PYPKGPREFIX}-SocksiPy-branch-[0-9]*

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
