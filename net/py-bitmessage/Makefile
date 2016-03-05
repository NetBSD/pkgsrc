# $NetBSD: Makefile,v 1.2 2016/03/05 11:29:11 jperkin Exp $

GITHUB_PROJECT=	PyBitmessage
DISTNAME=	${PYPKGPREFIX}-bitmessage-0.4.4
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Bitmessage/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=Bitmessage/PyBitmessage/}
COMMENT=	P2P communications protocol used to send encrypted messages
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

REPLACE_PYTHON+=	src/bitmessagemain.py
REPLACE_PYTHON+=	src/pyelliptic/cipher.py
REPLACE_PYTHON+=	src/pyelliptic/ecc.py
REPLACE_PYTHON+=	src/pyelliptic/hash.py
REPLACE_PYTHON+=	src/pyelliptic/openssl.py
REPLACE_PYTHON+=	src/qidenticon.py
REPLACE_PYTHON+=	src/singleton.py

# Hack
post-install:
	${RUN} rm -f ${DESTDIR}${PREFIX}/share/pybitmessage/helper_startup.py.orig
	${RUN} rm -f ${DESTDIR}${PREFIX}/share/pybitmessage/shared.py.orig

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
