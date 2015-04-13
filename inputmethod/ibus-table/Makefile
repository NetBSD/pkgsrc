# $NetBSD: Makefile,v 1.21 2015/04/13 23:12:42 rodent Exp $

DISTNAME=	ibus-table-1.9.2
CATEGORIES=	inputmethod
MASTER_SITES=	https://github.com/kaio/ibus-table/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	Table engine for IBus platform
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
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
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
