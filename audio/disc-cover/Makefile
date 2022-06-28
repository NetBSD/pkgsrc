# $NetBSD: Makefile,v 1.37 2022/06/28 11:30:54 wiz Exp $

DISTNAME=	disc-cover-1.5.6
PKGREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	http://www.vanhemert.co.uk/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.vanhemert.co.uk/disc-cover.html
COMMENT=	Generation of CD covers
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Audio-CD>=0.05:../../audio/p5-Audio-CD

USE_TOOLS+=		perl:run pod2man
REPLACE_PERL=		disc-cover

DCTMPL=			${PREFIX}/share/disc-cover/templates

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} && ${POD2MAN} disc-cover > disc-cover.1
	${SED} "s|@DCTMPL@|${DCTMPL}|g" <${WRKSRC}/disc-cover \
		>${WRKDIR}/disc-cover

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/disc-cover ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/disc-cover.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${DCTMPL}
	${INSTALL_DATA} ${WRKSRC}/templates/* ${DESTDIR}${DCTMPL}

.include "../../mk/bsd.pkg.mk"
