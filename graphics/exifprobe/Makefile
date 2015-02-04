# $NetBSD: Makefile,v 1.6 2015/02/04 20:49:06 joerg Exp $
#

DISTNAME=		exifprobe-2.0.1
CATEGORIES=		graphics
MASTER_SITES=		http://www.virtual-cafe.com/~dhh/tools.d/exifprobe.d/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE= http://www.virtual-cafe.com/~dhh/tools.d/exifprobe.d/exifprobe.html
COMMENT=		EXIF data extractor

# byteorder.h problems
MAKE_JOBS_SAFE=	no

CFLAGS.SunOS+=		-Du_int32_t=uint32_t

INSTALL_MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
