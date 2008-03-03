# $NetBSD: Makefile,v 1.20 2008/03/03 17:45:36 jlam Exp $
#

DISTNAME=		monotone-viz-0.15
PKGREVISION=		2
CATEGORIES=		devel scm
MASTER_SITES=		http://oandrieu.nerim.net/monotone-viz/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://oandrieu.nerim.net/monotone-viz/
COMMENT=		Visualize monotone ancestry graphs

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		monotone-viz
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--with-shared-sqlite
CONFIGURE_ARGS+=	--without-local-lablgtk

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/monotone-viz ${DESTDIR}${PREFIX}/bin

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/lablgtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
