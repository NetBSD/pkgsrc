# $NetBSD: Makefile,v 1.17 2014/11/05 10:35:00 obache Exp $

DISTNAME=	ibus-table-1.9.1
CATEGORIES=	inputmethod
MASTER_SITES=	https://github.com/kaio/ibus-table/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	Table engine for IBus platform
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config msgfmt
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	ibus-table.pc.in

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	engine/tabcreatedb.py
SUBST_SED.prefix=	-e 's|/usr/share|${PREFIX}/share|g'

REPLACE_PYTHON+=	engine/tabcreatedb.py
PYTHON_VERSIONS_INCOMPATIBLE=	26 27

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
