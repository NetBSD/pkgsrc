# $NetBSD: Makefile,v 1.9 2006/02/05 23:08:48 joerg Exp $
#

DISTNAME=		monotone-viz-0.12
PKGREVISION=		6
CATEGORIES=		devel
MASTER_SITES=		http://oandrieu.nerim.net/monotone-viz/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://oandrieu.nerim.net/monotone-viz/
COMMENT=		Visualize monotone ancestry graphs

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-local-lablgtk --with-shared-sqlite
USE_TOOLS+=		gmake
BUILD_TARGET=		monotone-viz
BUILD_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR}
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
