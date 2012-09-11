# $NetBSD: Makefile,v 1.28 2012/09/11 23:59:26 asau Exp $
#

DISTNAME=		bladeenc-0.94.2-src-stable
PKGNAME=		bladeenc-0.94.2
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://distfiles.aydogan.net/audio/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bladeenc.mp3.no/
COMMENT=		Free MPEG Audio Layer 3 encoder (not decoder)

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	share/doc/html/bladeenc ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/bladeenc.html ${DESTDIR}${PREFIX}/share/doc/html/bladeenc
	${INSTALL_MAN} ${WRKSRC}/bladeenc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
