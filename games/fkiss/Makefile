# $NetBSD: Makefile,v 1.29 2017/08/16 20:45:37 wiz Exp $
#

DISTNAME=		fkiss-0.33
PKGNAME=		fkiss-0.33a
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://www.oersted.co.jp/~yav/soft/fkiss/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.oersted.co.jp/~yav/soft/indexe.html#fkiss
COMMENT=		Kisekae viewer

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		fkiss-0.33a.diff
PATCH_DIST_STRIP=	-p1

DEPENDS+=		lha-[0-9]*:../../archivers/lha

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CFLAGS+=		-DUSE_STDARG -DHAVE_STDARG_H
CFLAGS+=		-DDEV_SOUND="\"${DEVOSSSOUND}\""
BUILD_TARGET=		fkiss
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

post-patch:
	${MV} ${WRKSRC}/sound.c ${WRKSRC}/sound.c.bak
	${SED} -e "s,XXXPREFIXXXX,${PREFIX},g" \
		<${WRKSRC}/sound.c.bak >${WRKSRC}/sound.c
	${MV} ${WRKSRC}/fkiss.man ${WRKSRC}/fkiss.man.bak
	${SED} -e "s,XXXPREFIXXXX,${PREFIX},g" \
		<${WRKSRC}/fkiss.man.bak >${WRKSRC}/fkiss.man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fkiss ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fkiss.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/fkiss.6
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/fkiss
	${INSTALL_DATA} ${WRKSRC}/fkissrc.smp \
		${DESTDIR}${PREFIX}/share/examples/fkiss/fkissrc
	${INSTALL_DATA} ${WRKSRC}/frkismi4.lzh \
		${DESTDIR}${PREFIX}/share/examples/fkiss
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/fkiss
	for i in ${WRKSRC}/*.doc; do \
		${SED} -f ${WRKSRC}/english.sed <$$i \
		    >${DESTDIR}${PREFIX}/share/doc/fkiss/`${BASENAME} $$i`; \
	done

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
