# $NetBSD: Makefile,v 1.1.1.1 2005/05/31 16:00:58 drochner Exp $
#

DISTNAME=		monotone-viz-0.9
CATEGORIES=		devel
MASTER_SITES=		http://oandrieu.nerim.net/monotone-viz/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://oandrieu.nerim.net/monotone-viz/
COMMENT=		Visualize monotone ancestry graphs

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
BUILD_TARGET=		monotone-viz
BUILD_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR}

do-install:
	${CP} ${WRKSRC}/monotone-viz ${PREFIX}/bin

.include "../../lang/ocaml/buildlink3.mk"
.include "../../x11/lablgtk2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
