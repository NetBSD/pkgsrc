# $NetBSD: Makefile,v 1.39 2000/11/26 11:34:56 mycroft Exp $
#

DISTNAME=		imlib-1.9.8.1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/imlib/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.labs.redhat.com/imlib/

BUILD_DEPENDS+=		${LOCALBASE}/bin/autoconf:../../devel/autoconf
BUILD_DEPENDS+=		${LOCALBASE}/bin/automake:../../devel/automake
DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		libungif-*:../../graphics/libungif
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		netpbm-*:../../graphics/netpbm
DEPENDS+=		png>=1.0.6:../../graphics/png
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
	cd ${WRKSRC} && autoconf && automake

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/imlib
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.gif *.html \
		${PREFIX}/share/doc/imlib
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/imlib.m4 \
		${LOCALBASE}/share/aclocal/imlib.m4

.include "../../mk/bsd.pkg.mk"
