# $NetBSD: Makefile,v 1.5 2002/09/24 09:34:37 jlam Exp $

DISTNAME=		gimp-1.2.3
PKGNAME=		gimp-base-1.2.3
PKGREVISION=		1
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
USE_X11=		yes
USE_GMAKE=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		yes
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

pre-build:
	${BUILDLINK_CC} -o ${WRKSRC}/docs/pdb_self_doc			\
		${FILESDIR}/pdb_self_doc.c

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} ||				\
		${LN} -fs ${PREFIX}/share/aclocal/gimp.m4		\
			${LOCALBASE}/share/aclocal/gimp.m4

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/mpeg-lib/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
