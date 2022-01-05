# $NetBSD: Makefile,v 1.7 2022/01/05 15:41:17 wiz Exp $

DISTNAME=	magic-wormhole-0.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/magic-wormhole/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/warner/magic-wormhole
COMMENT=	Securely transfer data between computers
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-attrs>=16.3.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-autobahn>=0.14.1:../../www/py-autobahn
DEPENDS+=	${PYPKGPREFIX}-automat-[0-9]*:../../devel/py-automat
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-humanize-[0-9]*:../../textproc/py-humanize
#DEPENDS+=	${PYPKGPREFIX}-hkdf-[0-9]*:../../security/py-hkdf
DEPENDS+=	${PYPKGPREFIX}-nacl-[0-9]*:../../security/py-nacl
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-spake2>=0.8:../../security/py-spake2
DEPENDS+=	${PYPKGPREFIX}-tqdm>=4.13.0:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-twisted>=17.5.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-txtorcon>=18.0.2:../../net/py-txtorcon

TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-magic-wormhole-transit-relay-[0-9]*:../../net/py-magic-wormhole-transit-relay
TEST_DEPENDS+=	${PYPKGPREFIX}-magic-wormhole-mailbox-server-[0-9]*:../../net/py-magic-wormhole-mailbox-server

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=		27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} wormhole wormhole-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
