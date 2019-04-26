# $NetBSD: Makefile,v 1.8 2019/04/26 13:14:08 maya Exp $

DISTNAME=	PyBitmessage-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//:tl}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Bitmessage/}
GITHUB_PROJECT=	PyBitmessage
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Bitmessage/PyBitmessage/
COMMENT=	P2P communications protocol used to send encrypted messages
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

REPLACE_PYTHON+=	src/bitmessagemain.py
REPLACE_PYTHON+=	src/depends.py
REPLACE_PYTHON+=	src/pyelliptic/cipher.py
REPLACE_PYTHON+=	src/pyelliptic/ecc.py
REPLACE_PYTHON+=	src/pyelliptic/hash.py
REPLACE_PYTHON+=	src/pyelliptic/openssl.py
REPLACE_PYTHON+=	src/qidenticon.py
REPLACE_PYTHON+=	src/singleton.py

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
