# $NetBSD: Makefile,v 1.12 2024/01/25 14:32:28 gdt Exp $
#

DISTNAME=		jpeg_ls_v2.2
PKGNAME=		jpeg_ls-2.2
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://kt.ijs.si/aleks/jpeg-ls/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kt.ijs.si/aleks/jpeg-ls/mirror.htm
COMMENT=		JPEG-LS codec (lossless/near-lossless codec)
# Boutique license not in pkgsrc: self contradictory and vague, referring to
# "commercial programs".
LICENSE=		generic-nonlicense

RESTRICTED=		No commercial use, no distribution fee.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

BUILD_DIRS=		Decoder Encoder
MAKE_FILE=		makefile

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Decoder/locod ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/Encoder/locoe ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/jpeg_ls
	${INSTALL_DATA} ${WRKSRC}/README* ${DESTDIR}${PREFIX}/share/doc/jpeg_ls
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/jpeg_ls
	${INSTALL_DATA} ${WRKSRC}/*.jls \
		${DESTDIR}${PREFIX}/share/examples/jpeg_ls
	${INSTALL_DATA} ${WRKSRC}/table* \
		${DESTDIR}${PREFIX}/share/examples/jpeg_ls

.include "../../mk/bsd.pkg.mk"
