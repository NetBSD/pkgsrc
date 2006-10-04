# $NetBSD: Makefile,v 1.7 2006/10/04 21:44:47 wiz Exp $
#

DISTNAME=		jpeg_ls_v2.2
PKGNAME=		jpeg_ls-2.2
CATEGORIES=		graphics
MASTER_SITES=		http://kt.ijs.si/aleks/jpeg-ls/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kt.ijs.si/aleks/jpeg-ls/mirror.htm
COMMENT=		JPEG-LS codec (lossless/near-lossless codec)

BUILD_DIRS=		${WRKSRC}/Decoder ${WRKSRC}/Encoder
MAKE_FILE=		makefile

LICENSE=		no-commercial-use
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Decoder/locod ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/Encoder/locoe ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jpeg_ls
	${INSTALL_DATA} ${WRKSRC}/README* ${PREFIX}/share/doc/jpeg_ls
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/jpeg_ls
	${INSTALL_DATA} ${WRKSRC}/*.jls ${PREFIX}/share/examples/jpeg_ls
	${INSTALL_DATA} ${WRKSRC}/table* ${PREFIX}/share/examples/jpeg_ls

.include "../../mk/bsd.pkg.mk"
