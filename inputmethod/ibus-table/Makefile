# $NetBSD: Makefile,v 1.31 2024/12/18 01:46:06 maya Exp $

DISTNAME=	ibus-table-1.9.2
PKGREVISION=	7
CATEGORIES=	inputmethod
MASTER_SITES=	https://github.com/kaio/ibus-table/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ibus/ibus/wiki
COMMENT=	Table engine for IBus platform
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config msgfmt
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	ibus-table.pc.in

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	engine/tabcreatedb.py
SUBST_SED.prefix=	-e 's|/usr/share|${PREFIX}/share|g'

REPLACE_PYTHON+=		engine/tabcreatedb.py
# Needs 'imp' removed in 3.12
PYTHON_VERSIONS_ACCEPTED=	310 311

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
