# $NetBSD: Makefile,v 1.1.1.1 1999/05/10 03:46:12 sakamoto Exp $

DISTNAME=	nkf-1.7
CATEGORIES=	japanese converters
MASTER_SITES=	ftp://ftp.win.ne.jp/pub/misc/

PATCH_SITES=	http://www.rs.civil.tohoku.ac.jp/~ito/ws/
PATCHFILES=	nkf.patch.txt

MAINTAINER=	kay@kaynet.or.jp

ALL_TARGET=	nkf
PATCH_DIST_ARGS+= -R -d ${WRKSRC}

post-extract:
	@cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} < ${FILESDIR}/nkf.post-extract

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nkf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nkf.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
