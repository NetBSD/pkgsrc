# $NetBSD: Makefile,v 1.1 2026/01/28 10:28:47 wiz Exp $

DISTNAME=	oscrypto-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=o/oscrypto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wbond/oscrypto
COMMENT=	TLS support using the OS crypto libraries
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-asn1crypto-[0-9]*:../../security/py-asn1crypto

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
