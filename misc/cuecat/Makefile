# $NetBSD: Makefile,v 1.19 2025/01/27 16:30:32 wiz Exp $

DISTNAME=	cuecat-0.2.1
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.gbppr.net/2600/cuecat/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://opensource.lineo.com/cuecat/cuecat_driver/
COMMENT=	Read and parse barcodes from your CueCat barcode reader

RESTRICTED=		Hardware manufacturer claims intellectual property infringement.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

# patch-ab changes the code from linux-specific to netbsd-specific
# (although it might also work with openbsd wscons...)
# Theoretically it wouldn't be too hard to improve the patch to work
# with both netbsd and linux.
ONLY_FOR_PLATFORM=	NetBSD-*-*

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin share/doc/cuecat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/read_cuecat ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/cuecat

.include "../../mk/bsd.pkg.mk"
