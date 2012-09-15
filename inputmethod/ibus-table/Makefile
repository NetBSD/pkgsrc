# $NetBSD: Makefile,v 1.6 2012/09/15 10:05:13 obache Exp $
#

DISTNAME=	ibus-table-1.3.0.20100621
PKGREVISION=	5
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	The Table engine for IBus platform
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config msgfmt
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	ibus-table.pc.in

CONFIGURE_ARGS+=	--disable-additional

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	engine/tabcreatedb.py
SUBST_SED.prefix=	-e 's|/usr/share|${PREFIX}/share|g'

SUBST_CLASSES+=		epython
SUBST_STAGE.epython=	pre-configure
SUBST_FILES.epython=	engine/ibus-engine-table.in
SUBST_FILES.epython+=	engine/ibus-table-createdb.in
SUBST_SED.epython=	-e 's;exec python;exec ${PYTHONBIN};g'

REPLACE_PYTHON+=	engine/tabcreatedb.py

.include "../../lang/python/application.mk"
BUILDLINK_ABI_DEPENDS.ibus+=	ibus>=1.1.0
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
