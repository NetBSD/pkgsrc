## $NetBSD: Makefile,v 1.38 2001/08/26 10:32:22 skrll Exp $

DISTNAME=		gnome-utils-1.4.0.2
CATEGORIES=		misc x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-utils/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Set of useful GNOME utilities and applications

BUILD_DEPENDS+=		autoconf-2.13:../../devel/autoconf
BUILD_DEPENDS+=		automake>=1.4:../../devel/automake
BUILD_DEPENDS+=		bison-*:../../devel/bison
BUILD_DEPENDS+=		xml-i18n-tools-*:../../textproc/xml-i18n-tools
DEPENDS+=		gnome-core>1.4.0:../../x11/gnome-core
DEPENDS+=		libgtop>=1.0.12:../../devel/libgtop

USE_CURSES=		YES
USE_GMAKE=		YES
USE_LIBINTL=		YES
USE_X11BASE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LOCALEDIR=${LOCALEDIR}

AUTOGEN_ENV=		NOCONFIGURE=1
AUTOGEN_ENV+=		srcdir=${WRKSRC}

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${AUTOGEN_ENV} ${SH} macros/autogen.sh

.include "../../mk/bsd.prefs.mk"

.if ${NEED_NCURSES} == "YES"
CONFIGURE_ARGS+=	--with-ncurses=${LOCALBASE}
CPPFLAGS+=		-I${LOCALBASE}/include
.endif

.include "../../mk/bsd.pkg.mk"
