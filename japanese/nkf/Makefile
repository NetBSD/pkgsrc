# $NetBSD: Makefile,v 1.4 2002/04/03 02:55:24 itojun Exp $

DISTNAME=	nkf-1.7
CATEGORIES=	japanese converters
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/cmd/nkf/

PATCH_SITES=	http://www.rs.civil.tohoku.ac.jp/~ito/ws/
PATCHFILES=	nkf.patch.txt

MAINTAINER=	kay@kaynet.or.jp
COMMENT=	Network Kanji code conversion Filter

ALL_TARGET=	nkf
PATCH_DIST_ARGS+= -R -d ${WRKSRC}

post-extract:
	@cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} < ${FILESDIR}/nkf.post-extract
	@${RM} -rf ${WRKSRC}/NKF

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nkf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nkf.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
