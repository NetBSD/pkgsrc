# $NetBSD: Makefile,v 1.4 2003/07/17 21:37:23 grant Exp $

DISTNAME=	Kochi-CID-0.018
PKGNAME=	kochi-cidfonts-0.018
CATEGORIES=	fonts x11 japanese
MASTER_SITES=	http://openlab.jp/efont/dist/Kochi-CID/current/
MASTER_SITES+=	http://khdd.net/Kochi-CID/current/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://khdd.net/Kochi-CID/
COMMENT=	Kochi-Mincho/Gothic scalable font in CID-Keyed format

NO_BUILD=	YES
FONTDIR=	${PREFIX}/share/ghostscript/Resource/CIDFont

do-install:
	${INSTALL_DATA_DIR} ${FONTDIR} && \
	${INSTALL_DATA} ${WRKSRC}/Kochi-* ${FONTDIR} && \
	${INSTALL_DATA} ${WRKSRC}/README-CID.sjis \
		${PREFIX}/share/doc/README.kochi-cidfonts

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
