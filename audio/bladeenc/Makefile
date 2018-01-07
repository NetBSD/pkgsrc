# $NetBSD: Makefile,v 1.31 2018/01/07 19:53:16 rillig Exp $
#

DISTNAME=		bladeenc-0.94.2-src-stable
PKGNAME=		bladeenc-0.94.2
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		http://distfiles.aydogan.net/audio/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://bladeenc.mp3.no/
COMMENT=		Free MPEG Audio Layer 3 encoder (not decoder)
LICENSE=		gnu-lgpl-v2.1

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes
AUTO_MKDIRS=		yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/bladeenc.html ${DESTDIR}${PREFIX}/share/doc/bladeenc/
	${INSTALL_MAN} ${WRKSRC}/bladeenc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
