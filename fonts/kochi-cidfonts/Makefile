# $NetBSD: Makefile,v 1.1.1.1 2003/02/15 23:02:07 kei Exp $

DISTNAME=	kochi-cidfonts-0.0.0.20030101
CATEGORIES=	fonts X11 japanese
MASTER_SITES=	http://openlab.jp/efont/dist/Kochi-CID/current/
MASTER_SITES+=	http://khdd.net/Kochi-CID/current/
EXTRACT_SUFX=	.bz2
DISTFILES=	Kochi-Gothic.afm${EXTRACT_SUFX} \
		Kochi-Gothic${EXTRACT_SUFX} \
		Kochi-Mincho.afm${EXTRACT_SUFX} \
		Kochi-Mincho${EXTRACT_SUFX}

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://khdd.net/Kochi-CID/
COMMENT=	Kochi-Mincho/Gothic scalable font in CID-Keyed format

EXTRACT_ONLY=	# empty
NO_BUILD=	YES
FONTDIR=	${PREFIX}/share/ghostscript/Resource/CIDFont

do-install:
	cd ${DISTDIR}; \
	${INSTALL_DATA} ${DISTFILES} ${FONTDIR}; \
	${GUNZIP_CMD} ${FONTDIR}/Kochi-*${EXTRACT_SUFX}

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
