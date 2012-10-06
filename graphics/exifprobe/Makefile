# $NetBSD: Makefile,v 1.4 2012/10/06 14:10:48 asau Exp $
#

DISTNAME=		exifprobe-2.0.1
CATEGORIES=		graphics
MASTER_SITES=		http://www.virtual-cafe.com/~dhh/tools.d/exifprobe.d/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE= http://www.virtual-cafe.com/~dhh/tools.d/exifprobe.d/exifprobe.html
COMMENT=		EXIF data extractor

INSTALL_MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
