# $NetBSD: Makefile,v 1.27 2006/02/05 23:09:22 joerg Exp $
#

DISTNAME=	sirius-0.8.0
PKGREVISION=	6
CATEGORIES=	games gnome
MASTER_SITES=	http://sirius.bitvis.nu/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sirius.bitvis.nu/
COMMENT=	Othello game for GNOME2

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
