# $NetBSD: Makefile,v 1.53 2023/01/03 17:37:11 wiz Exp $

DISTNAME=	quarry-0.2.0
PKGREVISION=	42
CATEGORIES=	games
#MASTER_SITES=	http://download.gna.org/quarry/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://home.gna.org/quarry/index.html
COMMENT=	Multi-purpose GUI for several board games

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
