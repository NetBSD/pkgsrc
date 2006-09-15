# $NetBSD: Makefile,v 1.42 2006/09/15 15:22:05 jmmv Exp $
#

DISTNAME=		gok-1.2.0
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gok/1.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME On-Screen Keyboard

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-gtk-doc

PKGCONFIG_OVERRIDE+=    gok-1.0.pc.in

GCONF2_SCHEMAS=		gok.schemas

.include "../../audio/esound/buildlink3.mk"
.include "../../audio/gnome-speech/buildlink3.mk"
.include "../../devel/at-spi/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gail/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
