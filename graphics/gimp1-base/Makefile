# $NetBSD: Makefile,v 1.5 2004/10/03 00:14:51 tv Exp $
#

DISTNAME=		gimp-1.2.5
PKGNAME=		gimp-base-1.2.5
PKGREVISION=		3
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.gimp.org/pub/gimp/v1.2/v1.2.5/ \
			ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/v1.2/v1.2.5/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gimp/v1.2/v1.2.5/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		hubertf@NetBSD.org
HOMEPAGE=		http://www.gimp.org/
COMMENT=		GNU Image Manipulation Program (base)

BUILD_USES_MSGFMT=	YES

CONFLICTS+=		gimp<=1.2.3 gimp>=2.0.0

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-python
# The "print" plugin gets built separately (../../print/gimp-print)
CONFIGURE_ARGS+=	--disable-print

# Add settings for MPEG, LIBMPEG, and GAP_DECODE_MPEG to properly support
# the MPEG library from graphics/mpeg-lib that changed its name, as the
# configure script will default to searching from -lmpeg.
#
CONFIGURE_ENV+=		MPEG="mpeg"
CONFIGURE_ENV+=		LIBMPEG="-lmpeg_lib"
CONFIGURE_ENV+=		GAP_DECODE_MPEG="gap_decode_mpeg"

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

MAKE_ENV+=		X11BASE=${X11BASE}
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

BUILD_DEFS+=		GIMP_WITH_HELPBROWSER

# Configuration files
PKG_SYSCONFSUBDIR=	gimp/1.2
EGDIR=			${PREFIX}/share/examples/gimp/1.2
CONF_FILES+=		${EGDIR}/gimprc ${PKG_SYSCONFDIR}/gimprc
CONF_FILES+=		${EGDIR}/gimprc_user ${PKG_SYSCONFDIR}/gimprc_user
CONF_FILES+=		${EGDIR}/gtkrc ${PKG_SYSCONFDIR}/gtkrc
CONF_FILES+=		${EGDIR}/gtkrc_user ${PKG_SYSCONFDIR}/gtkrc_user
CONF_FILES+=		${EGDIR}/ps-menurc ${PKG_SYSCONFDIR}/ps-menurc
CONF_FILES+=		${EGDIR}/unitrc ${PKG_SYSCONFDIR}/unitrc

pre-build:
	cd ${WRKSRC} &&							\
	${CC} -o ${WRKSRC}/docs/pdb_self_doc				\
		${FILESDIR}/pdb_self_doc.c

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} ||				\
		${LN} -fs ${PREFIX}/share/aclocal/gimp.m4		\
			${LOCALBASE}/share/aclocal/gimp.m4

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../multimedia/mpeg-lib/buildlink3.mk"
.if defined(GIMP_WITH_HELPBROWSER) && ${GIMP_WITH_HELPBROWSER} != "no"
PLIST_SUBST+=	HELPBROWSER=""
.include "../../x11/gnome-libs/buildlink3.mk"
.else
PLIST_SUBST+=	HELPBROWSER="@comment "
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
