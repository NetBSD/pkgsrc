# $NetBSD: Makefile,v 1.9 2004/02/19 23:30:45 jmmv Exp $
#

DISTNAME=		gok-0.8.4
PKGREVISION=		3
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GNOME:=desktop/2.4/2.4.1/sources/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME On-Screen Keyboard

DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ARGS+=	--disable-gtk-doc

PKGCONFIG_OVERRIDE+=    gok-1.0.pc.in

GCONF2_SCHEMAS=		gok.schemas

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/at-spi/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gail/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
