# $NetBSD: Makefile,v 1.3 2002/09/21 12:55:07 jlam Exp $
#

DISTNAME=		fkiss-0.32
CATEGORIES=		games
MASTER_SITES=		http://www.oersted.co.jp/~yav/soft/fkiss/

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.oersted.co.jp/~yav/soft/indexe.html#fkiss
COMMENT=		kisekae viewer

DEPENDS+=		lha-[0-9]*:../../archivers/lha

USE_BUILDLINK2=		yes
USE_X11=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CFLAGS+=		-DUSE_STDARG -DHAVE_STDARG_H

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
