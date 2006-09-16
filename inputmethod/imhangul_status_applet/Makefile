# $NetBSD: Makefile,v 1.23 2006/09/16 12:20:38 jmmv Exp $
#

DISTNAME=		imhangul_status_applet-0.3
PKGREVISION=		8
CATEGORIES=		korean inputmethod
MASTER_SITES=		http://download.kldp.net/imhangul/imhangul_status_applet/0.3/

MAINTAINER=		minskim@NetBSD.org
HOMEPAGE=		http://imhangul.kldp.net/\#APPLET
COMMENT=		GNOME2 applet to show imhangul status

DEPENDS+=		imhangul>=0.9.6:../../inputmethod/imhangul

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.1 gnome2-1.5
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes

GCONF2_SCHEMAS=		imhangul_status.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
