## $NetBSD: Makefile,v 1.50 2002/11/02 02:42:04 rh Exp $

DISTNAME=		gnome-utils-1.4.1
PKGREVISION=		3
CATEGORIES=		misc x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-utils/1.4/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Set of useful GNOME utilities and applications

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=		xml-i18n-tools-[0-9]*:../../textproc/xml-i18n-tools

USE_GMAKE=		YES
USE_X11BASE=		YES
USE_BUILDLINK2=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
CONFIGURE_ARGS+=	--localstatedir=${SCROLLKEEPER_DATADIR}

.include "../../textproc/scrollkeeper/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../devel/libgtop/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../lang/guile/buildlink2.mk"
.include "../../www/gtkhtml/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
