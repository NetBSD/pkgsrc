# $NetBSD: Makefile,v 1.13 2003/05/02 11:55:17 wiz Exp $

DISTNAME=		gimp-1.2.3
PKGNAME=		gimp-base-1.2.3
PKGREVISION=	5
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.gimp.org/pub/gimp/v1.2/v1.2.3/ \
			ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/v1.2/v1.2.3/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gimp/v1.2/v1.2.3/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.gimp.org/
COMMENT=		Image manipulation program similar to Photoshop[tm]

CONFLICTS+=		gimp<=1.2.3

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
USE_GMAKE=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-python

# Add settings for MPEG, LIBMPEG, and GAP_DECODE_MPEG to properly support
# the MPEG library from graphics/mpeg-lib that changed it's name, as the
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
	${BUILDLINK_CC} -o ${WRKSRC}/docs/pdb_self_doc			\
		${FILESDIR}/pdb_self_doc.c

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} ||				\
		${LN} -fs ${PREFIX}/share/aclocal/gimp.m4		\
			${LOCALBASE}/share/aclocal/gimp.m4

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/mpeg-lib/buildlink2.mk"
.if defined(GIMP_WITH_HELPBROWSER) && ${GIMP_WITH_HELPBROWSER} != "no"
PLIST_SUBST+=	HELPBROWSER=""
.include "../../x11/gnome-libs/buildlink2.mk"
.else
PLIST_SUBST+=	HELPBROWSER="@comment "
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.endif

.include "../../mk/bsd.pkg.mk"
