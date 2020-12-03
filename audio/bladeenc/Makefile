# $NetBSD: Makefile,v 1.32 2020/12/03 13:20:05 zafer Exp $
#

DISTNAME=		bladeenc-0.94.2-src-stable
PKGNAME=		bladeenc-0.94.2
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=	https://www.aydogan.net/distfiles/audio/

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
