# $NetBSD: Makefile,v 1.2 2003/07/17 21:37:24 grant Exp $

DISTNAME=	Kochi-OTF-0.018
PKGNAME=	kochi-otf-0.018
CATEGORIES=	fonts x11 japanese
MASTER_SITES=	http://openlab.jp/efont/dist/Kochi-CID/current/
MASTER_SITES+=	http://khdd.net/Kochi-CID/current/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://khdd.net/Kochi-CID/
COMMENT=	Kochi-Mincho/Gothic scalable font in OpenType format

NO_BUILD=	YES
FONTDIR=	${PREFIX}/share/ghostscript/Resource/Font

do-install:
	${INSTALL_DATA_DIR} ${FONTDIR} && \
	${INSTALL_DATA} ${WRKSRC}/Kochi-* ${FONTDIR} && \
	${INSTALL_DATA} ${WRKSRC}/README-OTF.sjis \
		${PREFIX}/share/doc/README.kochi-otf

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
