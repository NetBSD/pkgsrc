# $NetBSD: Makefile,v 1.22 2003/12/22 10:57:42 jmmv Exp $
#

DISTNAME=		bladeenc-0.94.2-src-stable
PKGNAME=		bladeenc-0.94.2
PKGREVISION=		2
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=		audio
MASTER_SITES=		http://bladeenc.mp3.no/source/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://bladeenc.mp3.no/
COMMENT=		Free MPEG Audio Layer 3 encoder (not decoder)

GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/bladeenc
	${INSTALL_DATA} ${WRKSRC}/bladeenc.html ${PREFIX}/share/doc/html/bladeenc
	${INSTALL_MAN} ${WRKSRC}/bladeenc.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
