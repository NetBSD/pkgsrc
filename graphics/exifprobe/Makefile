# $NetBSD: Makefile,v 1.5 2013/12/10 11:41:42 jperkin Exp $
#

DISTNAME=		exifprobe-2.0.1
CATEGORIES=		graphics
MASTER_SITES=		http://www.virtual-cafe.com/~dhh/tools.d/exifprobe.d/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE= http://www.virtual-cafe.com/~dhh/tools.d/exifprobe.d/exifprobe.html
COMMENT=		EXIF data extractor

CFLAGS.SunOS+=		-Du_int32_t=uint32_t

INSTALL_MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
