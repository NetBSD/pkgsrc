# $NetBSD: Makefile,v 1.48 2001/05/22 09:32:21 wiz Exp $
#

DISTNAME=		imlib-1.9.8.1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/imlib/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.nl.rasterman.com/imlib.html
COMMENT=		image manipulation library for X11

BUILD_DEPENDS+=		autoconf-2.13:../../devel/autoconf
BUILD_DEPENDS+=		automake-1.4:../../devel/automake
DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		libungif-*:../../graphics/libungif
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		netpbm-*:../../graphics/netpbm
DEPENDS+=		png>=1.0.11:../../graphics/png
DEPENDS+=		tiff>=3.5.4:../../graphics/tiff

USE_X11BASE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}
USE_GMAKE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CPPFLAGS=		-DENABLE_NLS
.endif

CPPFLAGS+=		-I${LOCALBASE}/include

pre-configure:
	cd ${WRKSRC} && ${SED} "s|@LOCALBASE@|${LOCALBASE}|" configure.in \
		> configure.in.tmp && ${MV} configure.in.tmp configure.in
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf && ${LOCALBASE}/bin/automake

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/imlib
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.gif *.html \
		${PREFIX}/share/doc/imlib
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/imlib.m4 \
		${LOCALBASE}/share/aclocal/imlib.m4

.include "../../mk/bsd.pkg.mk"
