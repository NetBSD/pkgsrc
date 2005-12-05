# $NetBSD: Makefile,v 1.14 2005/12/05 23:55:08 rillig Exp $
#

DISTNAME=		gimp-1.2.5
PKGNAME=		gimp-base-1.2.5
PKGREVISION=		4
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.gimp.org/pub/gimp/v1.2/v1.2.5/ \
			ftp://ftp.fu-berlin.de/unix/X11/graphics/gimp/v1.2/v1.2.5/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gimp/v1.2/v1.2.5/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gimp.org/
COMMENT=		GNU Image Manipulation Program (base)

BUILD_USES_MSGFMT=	YES

CONFLICTS+=		gimp<=1.2.3 gimp>=2.0.0

USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
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

MAKE_ENV+=		X11BASE=${X11BASE:Q}
PLIST_SUBST+=		LOCALBASE=${LOCALBASE:Q}

.include "options.mk"

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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../multimedia/mpeg-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
