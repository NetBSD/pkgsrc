## $NetBSD: Makefile,v 1.42 2001/10/13 08:30:25 rh Exp $

DISTNAME=		gnome-utils-1.4.1
CATEGORIES=		misc x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-utils/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Set of useful GNOME utilities and applications

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=		xml-i18n-tools-[0-9]*:../../textproc/xml-i18n-tools
DEPENDS+=		libgtop>=1.0.12:../../devel/libgtop

USE_CURSES=		YES
USE_GMAKE=		YES
USE_LIBINTL=		YES
USE_X11BASE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LOCALEDIR=${LOCALEDIR}

.include "../../mk/bsd.prefs.mk"

.if ${NEED_NCURSES} == "YES"
CONFIGURE_ARGS+=	--with-ncurses=${LOCALBASE}
CPPFLAGS+=		-I${LOCALBASE}/include
.endif

.include "../../devel/libglade/buildlink.mk"
.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
