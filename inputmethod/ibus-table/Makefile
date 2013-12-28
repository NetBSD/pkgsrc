# $NetBSD: Makefile,v 1.9 2013/12/28 09:02:31 obache Exp $
#

DISTNAME=	ibus-table-1.5.0
PKGREVISION=	1
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus.googlecode.com/files/

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

.include "../../lang/python/application.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
