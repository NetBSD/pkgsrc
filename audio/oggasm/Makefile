# $NetBSD: Makefile,v 1.24 2019/08/11 13:17:55 wiz Exp $
#

DISTNAME=	oggasm_1.4.0
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	rxg@NetBSD.org
# HOMEPAGE=	http://oggasm.sourceforge.net/
# but see http://us.geocities.com/pvachusk/programs/index.html
COMMENT=	Perform batch conversion of mp3s into oggs
LICENSE=	gnu-gpl-v2

DEPENDS+=	mpg123>=0.59.18:../../audio/mpg123
DEPENDS+=	vorbis-tools>=1.0.0.7:../../audio/vorbis-tools
DEPENDS+=	p5-MP3-Info>=1.00:../../audio/p5-MP3-Info

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	perl:run
REPLACE_PERL=	oggasm

NO_BUILD=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/oggasm ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/oggasm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
