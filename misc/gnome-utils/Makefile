# $NetBSD: Makefile,v 1.74 2004/04/26 22:07:06 snj Exp $

DISTNAME=		gnome-utils-1.4.1.2
PKGREVISION=		9
CATEGORIES=		misc x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-utils/1.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Set of useful GNOME utilities and applications

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=		xml-i18n-tools-[0-9]*:../../textproc/xml-i18n-tools

BUILDLINK_DEPENDS.gnome-panel=	gnome-panel<2.0

CONFLICTS=		coreutils<=5.0

USE_DIRS+=		gnome1-1.5
USE_GNU_TOOLS+=		make
USE_X11BASE=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		BUILD_GUILE=no
CONFIGURE_ENV+=		PKG_CONFIG_PATH="${LOCALBASE}/lib/pkgconfig:${X11BASE}/lib/pkgconfig"
CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gnome-objc/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
#.include "../../lang/guile14/buildlink3.mk"	# XXX: req. guile1[46] fix first
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../www/gtkhtml/buildlink3.mk"
.include "../../x11/gnome-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
