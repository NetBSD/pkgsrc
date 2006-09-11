# $NetBSD: Makefile,v 1.44 2006/09/11 17:07:48 wiz Exp $
#

DISTNAME=		mergeant-0.63
CATEGORIES=		databases gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/mergeant/0.63/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome-db.org/
COMMENT=		GNOME2 GNOME-DB database front-end

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake intltool perl pkg-config
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-gtk-doc
USE_LIBTOOL=		YES

.include "../../databases/libgda/buildlink3.mk"
.include "../../databases/libgnomedb/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
