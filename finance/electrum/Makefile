# $NetBSD: Makefile,v 1.12 2022/06/30 11:18:23 nia Exp $

VERSION=	4.1.5
DISTNAME=	Electrum-${VERSION}
PKGNAME=	electrum-${VERSION}
PKGREVISION=	3
CATEGORIES=	finance
MASTER_SITES=	https://download.electrum.org/${VERSION}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://electrum.org/
COMMENT=	Easy to use Bitcoin client
LICENSE=	gnu-gpl-v3

NO_BUILD=			yes
PYTHON_VERSIONS_INCOMPATIBLE=	27

# Ordered the same as in contrib/requirements.txt
DEPENDS+=	${PYPKGPREFIX}-ecdsa>=0.14:../../security/py-ecdsa
DEPENDS+=	${PYPKGPREFIX}-qrcode-[0-9]*:../../graphics/py-qrcode
DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.12:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-dns<2.0:../../net/py-dns
# Seems to work without qdarkstyle? Commented out as it's currently not packaged
#DEPENDS+=	${PYPKGPREFIX}-qdarkstyle<2.9:../../
DEPENDS+=	${PYPKGPREFIX}-aiorpcX>0.18:../../net/py-aiorpcX
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.3.0:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-aiohttp-socks>=0.3:../../www/py-aiohttp-socks
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-bitstring-[0-9]*:../../devel/py-bitstring
DEPENDS+=	${PYPKGPREFIX}-attrs>=19.2.0:../../devel/py-attrs
DEPENDS+=	libsecp256k1>=0.1:../../security/libsecp256k1

REPLACE_PYTHON+=	electrum/electrum
REPLACE_PYTHON+=	electrum/scripts/*.py

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/electrum/electrum.orig

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
