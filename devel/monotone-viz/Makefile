# $NetBSD: Makefile,v 1.15 2007/02/17 20:59:49 wiz Exp $
#

DISTNAME=		monotone-viz-0.15
CATEGORIES=		devel scm
MASTER_SITES=		http://oandrieu.nerim.net/monotone-viz/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://oandrieu.nerim.net/monotone-viz/
COMMENT=		Visualize monotone ancestry graphs

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-local-lablgtk --with-shared-sqlite
USE_TOOLS+=		gmake pkg-config
BUILD_TARGET=		monotone-viz
PKGSRC_MAKE_ENV+=	BUILDLINK_DIR=${BUILDLINK_DIR}
INSTALLATION_DIRS=	bin

do-install:
	${CP} ${WRKSRC}/monotone-viz ${PREFIX}/bin

.include "../../lang/ocaml/buildlink3.mk"
.include "../../x11/lablgtk2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
