# $NetBSD: Makefile,v 1.21 2003/07/17 21:21:58 grant Exp $
#

DISTNAME=		bladeenc-0.94.2-src-stable
PKGNAME=		bladeenc-0.94.2
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://bladeenc.mp3.no/source/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://bladeenc.mp3.no/
COMMENT=		Free MPEG Audio Layer 3 encoder (not decoder)

USE_GMAKE=		yes

WRKSRC:=		${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/bladeenc
	${INSTALL_DATA} ${WRKSRC}/bladeenc.html ${PREFIX}/share/doc/html/bladeenc
	${INSTALL_MAN} ${WRKSRC}/bladeenc.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
