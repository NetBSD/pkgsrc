# $NetBSD: Makefile,v 1.8 2005/05/22 20:08:08 jlam Exp $
#

DISTNAME=		imhangul_status_applet-0.2
PKGREVISION=		3
CATEGORIES=		korean inputmethod
MASTER_SITES=		http://download.kldp.net/imhangul/

MAINTAINER=		minskim@NetBSD.org
HOMEPAGE=		http://imhangul.kldp.net/\#APPLET
COMMENT=		GNOME2 applet to show imhangul status

DEPENDS=		imhangul>=0.9.6:../../inputmethod/imhangul

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

GCONF2_SCHEMAS=		imhangul_status.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
