# $NetBSD: Makefile,v 1.17 2017/08/01 16:47:40 wiz Exp $
#

DISTNAME=	cuecat-0.2.1
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.blort.org/cuecat/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://opensource.lineo.com/cuecat/cuecat_driver/
COMMENT=	Read and parse barcodes from your CueCat barcode reader

# patch-ab changes the code from linux-specific to netbsd-specific
# (although it might also work with openbsd wscons...)
# Theoretically it wouldn't be too hard to improve the patch to work
# with both netbsd and linux.
ONLY_FOR_PLATFORM=	NetBSD-*-*

RESTRICTED=	Hardware manufacturer claims intellectual property infringement.
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/read_cuecat ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/cuecat
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/cuecat

.include "../../mk/bsd.pkg.mk"
