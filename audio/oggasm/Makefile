# $NetBSD: Makefile,v 1.1.1.1 2002/05/22 12:26:16 zuntum Exp $
#

DISTNAME=	oggasm_1.4.0
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	audio
MASTER_SITES=	http://oggasm.sourceforge.net/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://oggasm.sourceforge.net/
COMMENT=	perform batch conversion of mp3s into oggs

DEPENDS+=	mpg123>=0.59.18:../../audio/mpg123
DEPENDS+=	vorbis-tools>=1.0.0.7:../../audio/vorbis-tools
DEPENDS+=	p5-MP3-Info>=1.00:../../audio/p5-MP3-Info

USE_PERL5=	yes
REPLACE_PERL=	${WRKSRC}/oggasm

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/oggasm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/oggasm.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
