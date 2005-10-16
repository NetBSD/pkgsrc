# $NetBSD: Makefile,v 1.19 2005/10/16 15:29:55 wiz Exp $
#

DISTNAME=	disc-cover-1.5.4
CATEGORIES=	audio
MASTER_SITES=	http://www.vanhemert.co.uk/files/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.vanhemert.co.uk/disc-cover.html
COMMENT=	Generation of CD covers

DEPENDS+=	p5-Audio-CD>=0.05:../../audio/p5-Audio-CD

USE_TOOLS+=		perl:run pod2man
REPLACE_PERL=		disc-cover

DCTMPL=	${PREFIX}/share/disc-cover/templates

INSTALLATION_DIRS=	bin man/man1

do-build:
	cd ${WRKSRC} && ${POD2MAN} disc-cover > disc-cover.1
	${SED} "s|@DCTMPL@|${DCTMPL}|g" <${WRKSRC}/disc-cover \
		>${WRKDIR}/disc-cover

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/disc-cover ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/disc-cover.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${DCTMPL}
	${INSTALL_DATA} ${WRKSRC}/templates/* ${DCTMPL}

.include "../../mk/bsd.pkg.mk"
