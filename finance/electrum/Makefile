# $NetBSD: Makefile,v 1.1 2020/04/14 20:05:49 js Exp $

VERSION=	3.3.8
DISTNAME=	Electrum-${VERSION}
PKGNAME=	electrum-${VERSION}
CATEGORIES=	finance
MASTER_SITES=	https://download.electrum.org/${VERSION}/

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://electrum.org/
COMMENT=	Easy to use Bitcoin client
LICENSE=	gnu-gpl-v3

NO_BUILD=			yes
PYTHON_VERSIONS_INCOMPATIBLE=	27

# Ordered the same as in contrib/requirements.txt
DEPENDS+=	${PYPKGPREFIX}-aes-[0-9]*:../../security/py-aes
DEPENDS+=	${PYPKGPREFIX}-ecdsa>=0.13:../../security/py-ecdsa
DEPENDS+=	${PYPKGPREFIX}-qrcode-[0-9]*:../../graphics/py-qrcode
DEPENDS+=	${PYPKGPREFIX}-protobuf-[0-9]*:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-jsonrpclib-pelix-[0-9]*:../../textproc/py-jsonrpclib-pelix
# Seems to work without qdarkstyle? Commented out as it's currently not packaged
#DEPENDS+=	${PYPKGPREFIX}-qdarkstyle-[0-9]*:../../
DEPENDS+=	${PYPKGPREFIX}-aiorpcX<0.19:../../net/py-aiorpcX
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.3.0:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-aiohttp-socks-[0-9]*:../../www/py-aiohttp-socks
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi

REPLACE_PYTHON+=	lib/*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../x11/py-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
