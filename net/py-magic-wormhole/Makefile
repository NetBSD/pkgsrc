# $NetBSD: Makefile,v 1.12 2025/04/05 20:02:29 gdt Exp $

DISTNAME=	magic-wormhole-0.18.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/magic-wormhole/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/warner/magic-wormhole
COMMENT=	Securely transfer data between computers
LICENSE=	mit

# in setup.py order
DEPENDS+=	${PYPKGPREFIX}-spake2>=0.9:../../security/py-spake2
DEPENDS+=	${PYPKGPREFIX}-nacl-[0-9]*:../../security/py-nacl
DEPENDS+=	${PYPKGPREFIX}-iterable-io>=1.0.0:../../devel/py-iterable-io
DEPENDS+=	${PYPKGPREFIX}-attrs>=16.3.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-twisted>=17.5.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-autobahn>=0.14.1:../../www/py-autobahn
DEPENDS+=	${PYPKGPREFIX}-automat-[0-9]*:../../devel/py-automat
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-tqdm>=4.13.0:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-humanize-[0-9]*:../../textproc/py-humanize
DEPENDS+=	${PYPKGPREFIX}-txtorcon>=18.0.2:../../net/py-txtorcon
DEPENDS+=	${PYPKGPREFIX}-zipstream-ng>=1.7.1:../../archivers/py-zipstream-ng

# \todo Align these to setup.py
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-magic-wormhole-transit-relay-[0-9]*:../../net/py-magic-wormhole-transit-relay
TEST_DEPENDS+=	${PYPKGPREFIX}-magic-wormhole-mailbox-server-[0-9]*:../../net/py-magic-wormhole-mailbox-server

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} wormhole wormhole-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
