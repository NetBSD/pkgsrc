# $NetBSD: Makefile,v 1.86 2004/04/23 16:24:14 minskim Exp $
#

DISTNAME=		imlib-1.9.14
PKGREVISION=		6
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/imlib/1.9/}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.nl.rasterman.com/imlib.html
COMMENT=		Image manipulation library for X11

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_X11=		yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	imlib.pc.in
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
UNLIMIT_RESOURCES=	datasize

CPPFLAGS+=		-DENABLE_NLS
CONFIGURE_ENV+=		ac_cv_path_CONVERT_PROG="${LOCALBASE}/bin/convert"
CONFIGURE_ENV+=		X_LDFLAGS="${X_LDFLAGS}"
CONFIGURE_ARGS+=	--sysconfdir="${PKG_SYSCONFDIR}"

PKG_SYSCONFSUBDIR=	imlib
EGDIR=			${PREFIX}/share/examples/imlib

USE_PKGINSTALL=		yes
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

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/imlib
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.gif *.html \
		${PREFIX}/share/doc/imlib

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
