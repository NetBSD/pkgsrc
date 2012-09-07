# $NetBSD: Makefile,v 1.12 2012/09/07 19:16:59 adam Exp $
#

DISTNAME=	scim-python-0.1.13rc1
PKGREVISION=	12
CATEGORIES=	inputmethod python
MASTER_SITES=	http://scim-python.googlecode.com/files/
DISTFILES=	${DEFAULT_DISTFILES} ${DBTAR}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/scim-python/
COMMENT=	Python wrapper for Smart Common Input Method platform
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-enchant-[0-9]*:../../textproc/py-enchant

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config msgfmt

# taken from ${WRKSRC}/python/engine/PinYin/Makefile.in
DBVER=			0.1.10.5
DBTAR=			pinyin-database-${DBVER}.tar.bz2

post-extract:
	${TOUCH} ${WRKSRC}/python/engine/PinYin/${DBTAR}
	${CP} ${WRKDIR}/py.db ${WRKSRC}/python/engine/PinYin/py.db

PY_PATCHPLIST=		yes

REPLACE_PYTHON+=	python/engine/XingMa/XMCreateDB.py

.include "../../inputmethod/scim/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
