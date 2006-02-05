# $NetBSD: Makefile,v 1.12 2006/02/05 23:08:13 joerg Exp $
#

DISTNAME=	oggasm_1.4.0
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://oggasm.sourceforge.net/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://oggasm.sourceforge.net/
COMMENT=	Perform batch conversion of mp3s into oggs

DEPENDS+=	mpg123>=0.59.18:../../audio/mpg123
DEPENDS+=	vorbis-tools>=1.0.0.7:../../audio/vorbis-tools
DEPENDS+=	p5-MP3-Info>=1.00:../../audio/p5-MP3-Info

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	perl:run
REPLACE_PERL=	oggasm

NO_BUILD=	yes

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/oggasm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/oggasm.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
