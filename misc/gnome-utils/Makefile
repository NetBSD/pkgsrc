## $NetBSD: Makefile,v 1.43 2001/12/12 16:20:48 wiz Exp $

DISTNAME=		gnome-utils-1.4.1
CATEGORIES=		misc x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-utils/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Set of useful GNOME utilities and applications

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=		xml-i18n-tools-[0-9]*:../../textproc/xml-i18n-tools
DEPENDS+=		libgtop>=1.0.12:../../devel/libgtop

USE_GMAKE=		YES
USE_X11BASE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}

.include "../../devel/libglade/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
