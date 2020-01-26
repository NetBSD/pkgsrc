# $NetBSD: Makefile,v 1.29 2020/01/26 17:31:17 rillig Exp $

DISTNAME=	tworld-1.3.2
PKGNAME=	${DISTNAME:S/^t/tile/}
CATEGORIES=	games
MASTER_SITES=	http://www.muppetlabs.com/~breadbox/pub/software/tworld/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.muppetlabs.com/~breadbox/software/tworld/
COMMENT=	Game based on Chip's Challenge
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	date gmake
GNU_CONFIGURE=	YES

BUILD_TARGET=	tworld

MAKE_ENV+=	ECHO=${ECHO:Q} DATE=${DATE:Q}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/tworld/sets
INSTALLATION_DIRS+=	share/tworld/data
INSTALLATION_DIRS+=	share/tworld/res
INSTALLATION_DIRS+=	share/doc/tworld
INSTALLATION_DIRS+=	${PKGMANDIR}/man6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tworld ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/sets/*.dac ${DESTDIR}${PREFIX}/share/tworld/sets
	${INSTALL_DATA} ${WRKSRC}/data/*.dat ${DESTDIR}${PREFIX}/share/tworld/data
	${INSTALL_DATA} ${WRKSRC}/res/rc ${DESTDIR}${PREFIX}/share/tworld/res
	${INSTALL_DATA} ${WRKSRC}/res/*.bmp ${DESTDIR}${PREFIX}/share/tworld/res
	${INSTALL_DATA} ${WRKSRC}/res/*.txt ${DESTDIR}${PREFIX}/share/tworld/res
	${INSTALL_DATA} ${WRKSRC}/res/*.wav ${DESTDIR}${PREFIX}/share/tworld/res
	${INSTALL_MAN} ${WRKSRC}/docs/tworld.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6
	${INSTALL_DATA} ${WRKSRC}/README \
		${WRKSRC}/docs/tworld.html \
		${DESTDIR}${PREFIX}/share/doc/tworld

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
