# $NetBSD: Makefile,v 1.7 2004/01/20 12:07:43 agc Exp $
#

DISTNAME=	oggasm_1.4.0
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	audio
MASTER_SITES=	http://oggasm.sourceforge.net/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://oggasm.sourceforge.net/
COMMENT=	Perform batch conversion of mp3s into oggs

DEPENDS+=	mpg123>=0.59.18:../../audio/mpg123
DEPENDS+=	vorbis-tools>=1.0.0.7:../../audio/vorbis-tools
DEPENDS+=	p5-MP3-Info>=1.00:../../audio/p5-MP3-Info

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_PERL5=	yes
REPLACE_PERL=	oggasm

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/oggasm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/oggasm.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
