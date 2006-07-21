# $NetBSD: Makefile,v 1.13 2006/07/21 14:27:56 jlam Exp $
#

DISTNAME=		monotone-viz-0.14
PKGREVISION=		1
CATEGORIES=		devel
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
