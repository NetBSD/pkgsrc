# $NetBSD: Makefile,v 1.102 2008/02/02 16:43:34 heinz Exp $

DISTNAME=	imlib-1.9.15
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/imlib/1.9/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nl.rasterman.com/imlib.html
COMMENT=	Image manipulation library for X11

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	imlib.pc.in
UNLIMIT_RESOURCES=	datasize

CPPFLAGS+=		-DENABLE_NLS
CONFIGURE_ENV+=		ac_cv_path_CONVERT_PROG="${LOCALBASE}/bin/convert"
CONFIGURE_ENV+=		X_LDFLAGS=${X_LDFLAGS:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

PKG_SYSCONFSUBDIR=	imlib
EGDIR=			${PREFIX}/share/examples/imlib

CONF_FILES=		${EGDIR}/imrc ${PKG_SYSCONFDIR}/imrc
CONF_FILES+=		${EGDIR}/im_palette.pal \
			${PKG_SYSCONFDIR}/im_palette.pal
CONF_FILES+=		${EGDIR}/im_palette-small.pal \
			${PKG_SYSCONFDIR}/im_palette-small.pal
CONF_FILES+=		${EGDIR}/im_palette-tiny.pal \
			${PKG_SYSCONFDIR}/im_palette-tiny.pal

# The following ensures that `imlib-config --libs' includes the correct
# linker flags for linking the X11 libs.
#
X_LDFLAGS=		${X11_LDFLAGS}

.include "../../mk/bsd.prefs.mk"
.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--x-includes=${X11PREFIX:Q}/include
.endif

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/imlib
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.gif *.html \
		${DESTDIR}${PREFIX}/share/doc/imlib

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
