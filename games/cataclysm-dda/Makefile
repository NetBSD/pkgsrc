# $NetBSD: Makefile,v 1.5 2024/05/06 08:40:25 jperkin Exp $

PKGREVISION= 1
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Post-apocalyptic turn-based survival game (text-only version)

CONFLICTS+=	cataclysm-dda-sdl-[0-9]*

BUILD_TARGET=	cataclysm localization

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cataclysm ${DESTDIR}${PREFIX}/bin
.for target in core font json mods names raw motd credits title
	cd ${WRKSRC}/data && ${PAX} -rw -pp ${target} \
	    ${DESTDIR}${PREFIX}/share/cataclysm-dda
.endfor
	${INSTALL_DATA} ${WRKSRC}/data/changelog.txt \
	    ${DESTDIR}${PREFIX}/share/cataclysm-dda
	${INSTALL_DATA} ${WRKSRC}/data/cataicon.ico \
	    ${DESTDIR}${PREFIX}/share/cataclysm-dda
	${INSTALL_DATA} ${WRKSRC}/data/fontdata.json \
	    ${DESTDIR}${PREFIX}/share/cataclysm-dda
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt \
	    ${DESTDIR}${PREFIX}/share/cataclysm-dda
	cd ${WRKSRC} && LOCALE_DIR=${DESTDIR}${PREFIX}/share/locale ${SH} lang/compile_mo.sh

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
