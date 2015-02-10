# $NetBSD: Makefile,v 1.12 2015/02/10 22:32:03 snj Exp $

DISTNAME=		bos_1_1
PKGNAME=		bos-1.1
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		http://www.boswars.org/dist/releases/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.boswars.org/
COMMENT=		Invasion - Battle of Survival (real-time strategy game)

DEPENDS+=		stratagus>=2.1:../../games/stratagus

INSTALLATION_DIRS=	bin

USE_TOOLS+=	pax

do-build:
	${SED} -e "s|@LOCALBASE@|${LOCALBASE}|" \
		-e "s|@PREFIX@|${PREFIX}|" ${FILESDIR}/bos > \
		${WRKSRC}/bos

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bos ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/bos
	cd ${WRKSRC} && pax -pe -rw data ${DESTDIR}${PREFIX}/share/bos
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/bos
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/bos

.include "../../mk/bsd.pkg.mk"
