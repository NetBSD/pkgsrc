# $NetBSD: Makefile,v 1.17 2002/03/14 15:42:40 agc Exp $
#

DISTNAME=		bladeenc-0.94.2-src-stable
PKGNAME=		bladeenc-0.94.2
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://bladeenc.mp3.no/source/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://bladeenc.mp3.no/
COMMENT=		Free MPEG Audio Layer 3 encoder (not decoder)

USE_GMAKE=		yes

WRKSRC:=		${WRKDIR}/${PKGNAME}

GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bladeenc
	${INSTALL_DATA} ${WRKSRC}/bladeenc.html ${PREFIX}/share/doc/bladeenc

.include "../../mk/bsd.pkg.mk"
