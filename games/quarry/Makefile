# $NetBSD: Makefile,v 1.1.1.1 2008/03/13 16:06:16 wiz Exp $
#

DISTNAME=	quarry-0.2.0
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/quarry/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.gna.org/quarry/index.html
COMMENT=	Multi-purpose GUI for several board games

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.4
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
