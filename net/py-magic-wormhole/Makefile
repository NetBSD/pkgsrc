# $NetBSD: Makefile,v 1.13 2025/04/07 19:47:23 gdt Exp $

DISTNAME=	magic-wormhole-0.18.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/magic-wormhole/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/warner/magic-wormhole
COMMENT=	Securely transfer data between computers
LICENSE=	mit

# pyproject.toml
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=64.0.0:../../devel/py-setuptools

# setup.py extras_requires.build
# twine: for PyPi
#TOOL_DEPENDS+=	${PYPKGPREFIX}-dulwich-[0-9]*:../../devel/py-dulwich
# readme_renderer: ?
# gpg: ? (for upload)
# wheel

# not declared, but used in setup.py
TOOL_DEPENDS+=	${PYPKGPREFIX}-versioneer-[0-9]*:../../devel/py-versioneer

# setup.py install_requires
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

# setup.py install_requires dev
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
TEST_DEPENDS+=	${PYPKGPREFIX}-flakes>=1.2.3:../../devel/py-flakes
TEST_DEPENDS+=	${PYPKGPREFIX}-magic-wormhole-transit-relay-[0-9]*:../../net/py-magic-wormhole-transit-relay
TEST_DEPENDS+=	${PYPKGPREFIX}-magic-wormhole-mailbox-server-[0-9]*:../../net/py-magic-wormhole-mailbox-server

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} wormhole wormhole-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
