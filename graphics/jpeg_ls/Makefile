# $NetBSD: Makefile,v 1.10 2012/10/06 14:11:01 asau Exp $
#

DISTNAME=		jpeg_ls_v2.2
PKGNAME=		jpeg_ls-2.2
CATEGORIES=		graphics
MASTER_SITES=		http://kt.ijs.si/aleks/jpeg-ls/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kt.ijs.si/aleks/jpeg-ls/mirror.htm
COMMENT=		JPEG-LS codec (lossless/near-lossless codec)
LICENSE=		no-commercial-use

BUILD_DIRS=		${WRKSRC}/Decoder ${WRKSRC}/Encoder
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
