# $NetBSD: Makefile,v 1.65 2003/09/28 09:13:58 jlam Exp $

DISTNAME=		gnome-utils-1.4.1.2
PKGREVISION=		4
CATEGORIES=		misc x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-utils/1.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Set of useful GNOME utilities and applications

DEPENDS+=		gnome1-dirs>=1.2:../../misc/gnome1-dirs
BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=		xml-i18n-tools-[0-9]*:../../textproc/xml-i18n-tools

BUILDLINK_DEPENDS.gnome-panel=	gnome-panel<2.0

CONFLICTS=		coreutils<=5.0

USE_GMAKE=		YES
USE_X11BASE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		BUILD_GUILE=no
CONFIGURE_ENV+=		PKG_CONFIG_PATH="${LOCALBASE}/lib/pkgconfig:${X11BASE}/lib/pkgconfig"
CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/gnome-objc/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../devel/libgtop/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
#.include "../../lang/guile14/buildlink2.mk"	# XXX: req. guile1[46] fix first
.include "../../www/gtkhtml/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
