# $NetBSD: Makefile,v 1.9 2005/01/03 15:59:12 wiz Exp $
#

DISTNAME=	oggasm_1.4.0
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	2
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
