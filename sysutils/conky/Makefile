# $NetBSD: Makefile,v 1.69 2024/05/29 16:34:23 adam Exp $
#

DISTNAME=	conky-1.9.0
PKGREVISION=	62
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=conky/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://conky.sourceforge.net/
COMMENT=	Free, light-weight system monitor for X
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config aclocal autoconf autoheader automake

CONFIGURE_ARGS+=	--enable-imlib2
CONFIGURE_ARGS+=	--enable-curl --enable-rss
CONFIGURE_ARGS+=	--enable-weather-metar --enable-weather-xoap
# devel/tolua++ was deeply broken by the lua 5.1 to 5.2 update and got
# removed; disable lua support for now
CONFIGURE_ARGS+=	--disable-lua
CONFIGURE_ARGS+=	--disable-ncurses
# CONFIGURE_ARGS+=	--enable-lua-cairo --enable-lua-imlib2

EGDIR=		share/examples/conky
OWN_DIRS=	${PKG_SYSCONFDIR}/conky
CONF_FILES=	${EGDIR}/conky.conf ${PKG_SYSCONFDIR}/conky/conky.conf
CONF_FILES+=	${EGDIR}/conky_no_x11.conf ${PKG_SYSCONFDIR}/conky/conky_no_x11.conf

CPPFLAGS.NetBSD+=	-D_KMEMUSER

pre-configure:
	set -e; cd ${WRKSRC};	\
	aclocal; autoheader; automake -a --foreign -i; autoconf

post-install:
	${INSTALL_DATA} files/conkyrc ${DESTDIR}${PREFIX}/${EGDIR}

#.include "../../devel/tolua++/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
