# $NetBSD: Makefile,v 1.128 2020/06/05 12:49:00 jperkin Exp $

DISTNAME=	imlib-1.9.15
PKGREVISION=	21
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/imlib/1.9/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.nl.rasterman.com/imlib.html
COMMENT=	Image manipulation library for X11

DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	imlib.pc.in
UNLIMIT_RESOURCES=	datasize

CPPFLAGS+=		-DENABLE_NLS
CONFIGURE_ENV+=		ac_cv_path_CONVERT_PROG="${LOCALBASE}/bin/convert"
CONFIGURE_ENV+=		X_LDFLAGS=${X_LDFLAGS:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-shm

PKG_SYSCONFSUBDIR=	imlib
EGDIR=			${PREFIX}/share/examples/imlib

CONF_FILES=		${EGDIR}/imrc ${PKG_SYSCONFDIR}/imrc
CONF_FILES+=		${EGDIR}/im_palette.pal \
			${PKG_SYSCONFDIR}/im_palette.pal
CONF_FILES+=		${EGDIR}/im_palette-small.pal \
			${PKG_SYSCONFDIR}/im_palette-small.pal
CONF_FILES+=		${EGDIR}/im_palette-tiny.pal \
			${PKG_SYSCONFDIR}/im_palette-tiny.pal

SUBST_CLASSES+=			imlib-config
SUBST_FILES.imlib-config=	imlib-config
SUBST_SED.imlib-config=		-e 's,no --,${PREFIX}/bin/gtk-config --,'
SUBST_STAGE.imlib-config=	post-configure

# The following ensures that `imlib-config --libs' includes the correct
# linker flags for linking the X11 libs.
#
X_LDFLAGS=		${X11_LDFLAGS}

CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/imlib
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.gif *.html \
		${DESTDIR}${PREFIX}/share/doc/imlib

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
