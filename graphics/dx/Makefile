# $NetBSD: Makefile,v 1.16 2002/09/04 14:47:36 agc Exp $

DISTNAME=	dx-4.1.3
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.research.ibm.com/dx/srcDownload/srcArchive/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.research.ibm.com/dx/
COMMENT=	Open Visualization Data Explorer

USE_BUILDLINK_ONLY=	yes
USE_X11BASE=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-javadx
CONFIGURE_ENV+=		LEX="flex -l"

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

CPPFLAGS+=		-I${BUILDLINK_DIR}/include/freetype	# freetype.h

# Override ARCH to avoid picking up a bad ${ARCH} during the build.
MAKE_ENV+=		ARCH=""
CONFIGURE_ENV+=		ARCH=""

# Remove "-I/usr/include -I/usr/local/include" from the INCLUDES, and
# "-L/usr/X11R6/lib -L/usr/local/lib" from the *_LDADD  passed to
# the compiler, as this defeats buildlink.
#
post-patch:
	cd ${WRKSRC};							\
	files=`${FIND} . -name "Makefile.in" -print`;			\
	for file in $${files}; do					\
		${SED}	-e "/^INCLUDES.*=.*/s|[ 	]*-I/usr/include[ 	]*-I/usr/local/include||" \
			-e "/^[^ ]*LDADD.*=.*/s|[ 	]*-L/usr/X11R6/lib[ 	]*-L/usr/local/lib||" \
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

.include "../../devel/netcdf/buildlink.mk"
.include "../../graphics/Mesa/buildlink.mk"
.include "../../graphics/freetype-lib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../mk/motif.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
