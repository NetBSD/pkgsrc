# $NetBSD: Makefile,v 1.69 2002/08/25 18:39:11 jlam Exp $
#

DISTNAME=		imlib-1.9.14
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/imlib/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.nl.rasterman.com/imlib.html
COMMENT=		image manipulation library for X11

USE_X11BASE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}
USE_GMAKE=		yes
UNLIMIT_RESOURCES=	datasize

USE_BUILDLINK2=		yes

CPPFLAGS+=		-DENABLE_NLS
CONFIGURE_ENV+=		ac_cv_path_CONVERT_PROG="${LOCALBASE}/bin/convert"
CONFIGURE_ENV+=		X_LDFLAGS="${X_LDFLAGS}"

# The following ensures that `imlib-config --libs' includes the correct
# linker flags for linking the X11 libs.
#
X_LDFLAGS=		-Wl,-R${X11BASE}/lib -L${X11BASE}/lib

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/imlib
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.gif *.html \
		${PREFIX}/share/doc/imlib
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/imlib.m4 \
		${LOCALBASE}/share/aclocal/imlib.m4

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../graphics/netpbm/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
