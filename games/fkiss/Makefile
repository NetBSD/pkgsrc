# $NetBSD: Makefile,v 1.7 2003/12/03 23:45:29 ben Exp $
#

DISTNAME=		fkiss-0.32
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://www.oersted.co.jp/~yav/soft/fkiss/

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://www.oersted.co.jp/~yav/soft/indexe.html#fkiss
COMMENT=		Kisekae viewer

DEPENDS+=		lha-[0-9]*:../../archivers/lha

USE_BUILDLINK2=		yes
USE_X11=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CFLAGS+=		-DUSE_STDARG -DHAVE_STDARG_H
CFLAGS+=		-DDEV_SOUND=\"\\\"${DEVOSSSOUND}\\\"\"

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

.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
