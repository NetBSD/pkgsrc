# $NetBSD: Makefile,v 1.22 2025/05/30 23:13:19 gdt Exp $

# Work around setuptools insisting that distfiles not match the (pypi)
# package name.
VERSION=	0.19.2
DISTNAME=	magic_wormhole-${VERSION}
PKGNAME=	${PYPKGPREFIX}-magic-wormhole-${VERSION}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/magic-wormhole/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/warner/magic-wormhole
COMMENT=	Securely transfer data between computers
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	39

# pyproject.toml
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

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
DEPENDS+=	${PYPKGPREFIX}-attrs>=19.2.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-twisted>=17.5.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-autobahn>=0.14.1:../../www/py-autobahn
DEPENDS+=	${PYPKGPREFIX}-automat-[0-9]*:../../devel/py-automat
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-tqdm>=4.13.0:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-humanize-[0-9]*:../../textproc/py-humanize
DEPENDS+=	${PYPKGPREFIX}-txtorcon>=18.0.2:../../net/py-txtorcon
DEPENDS+=	${PYPKGPREFIX}-zipstream-ng>=1.7.1:../../archivers/py-zipstream-ng
DEPENDS+=	${PYPKGPREFIX}-iterable-io>=1.0.0:../../devel/py-iterable-io
DEPENDS+=	${PYPKGPREFIX}-qrcode>=8.0:../../graphics/py-qrcode

# setup.py install_requires dev
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
TEST_DEPENDS+=	${PYPKGPREFIX}-flakes>=1.2.3:../../devel/py-flakes
TEST_DEPENDS+=	${PYPKGPREFIX}-magic-wormhole-transit-relay>=0.3.1:../../net/py-magic-wormhole-transit-relay # XXX setup.py says ==0.3.1 but 0.4.0 seems OK
TEST_DEPENDS+=	${PYPKGPREFIX}-magic-wormhole-mailbox-server>=0.3.1:../../net/py-magic-wormhole-mailbox-server # XXX setup.py says ==0.3.1 but 0.4.0 seems OK
#TEST_DEPENDS+=	${PYPKGPREFIX}-py-test-twisted-[0-9]*:../../net/py-test-twisted

USE_LANGUAGES=	# none

AUTO_MKDIRS=	yes

PYTHON_SELF_CONFLICT=	yes # completion files

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} wormhole wormhole-${PYVERSSUFFIX} || ${TRUE}
	${INSTALL_DATA} ${WRKSRC}/wormhole_complete.bash \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/wormhole
	${INSTALL_DATA} ${WRKSRC}/wormhole_complete.fish \
		${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/wormhole.fish
	${INSTALL_DATA} ${WRKSRC}/wormhole_complete.zsh \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/_wormhole

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
