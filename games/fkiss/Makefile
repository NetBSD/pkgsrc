# $NetBSD: Makefile,v 1.16 2005/02/14 10:15:05 uebayasi Exp $
#

DISTNAME=		fkiss-0.33
PKGNAME=		fkiss-0.33a
CATEGORIES=		games
MASTER_SITES=		http://www.oersted.co.jp/~yav/soft/fkiss/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.oersted.co.jp/~yav/soft/indexe.html#fkiss
COMMENT=		Kisekae viewer

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=             fkiss-0.33a.diff
PATCH_DIST_STRIP=       -p1

DEPENDS+=		lha-[0-9]*:../../archivers/lha

USE_BUILDLINK3=		yes
USE_X11=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
CFLAGS+=		-DUSE_STDARG -DHAVE_STDARG_H
CFLAGS+=		-DDEV_SOUND="\"${DEVOSSSOUND}\""
BUILD_TARGET=		fkiss

post-patch:
	${MV} ${WRKSRC}/sound.c ${WRKSRC}/sound.c.bak
	${SED} -e "s,XXXPREFIXXXX,${PREFIX},g" \
		<${WRKSRC}/sound.c.bak >${WRKSRC}/sound.c
	${MV} ${WRKSRC}/fkiss.man ${WRKSRC}/fkiss.man.bak
	${SED} -e "s,XXXPREFIXXXX,${PREFIX},g" \
		<${WRKSRC}/fkiss.man.bak >${WRKSRC}/fkiss.man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fkiss ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fkiss.man ${PREFIX}/man/man6/fkiss.6
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/fkiss
	${INSTALL_DATA} ${WRKSRC}/fkissrc.smp \
		${PREFIX}/share/examples/fkiss/fkissrc
	${INSTALL_DATA} ${WRKSRC}/frkismi4.lzh ${PREFIX}/share/examples/fkiss
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fkiss
	for i in ${WRKSRC}/*.doc; do \
		${SED} -f ${WRKSRC}/english.sed <$$i \
			>${PREFIX}/share/doc/fkiss/`${BASENAME} $$i`; \
	done

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
