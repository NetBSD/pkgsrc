# $NetBSD: Makefile,v 1.70 2011/11/01 06:00:51 sbd Exp $
#

DISTNAME=		mergeant-0.66
PKGREVISION=		15
CATEGORIES=		databases gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/mergeant/0.66/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome-db.org/
COMMENT=		GNOME2 GNOME-DB database front-end

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake intltool perl pkg-config msgfmt
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-gtk-doc
USE_LIBTOOL=		YES

.include "../../databases/libgda/buildlink3.mk"
.include "../../databases/libgnomedb/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
