# $NetBSD: Makefile,v 1.1.1.1 2002/07/14 09:40:30 rh Exp $
#

DISTNAME=		fkiss-0.32
CATEGORIES=		games
MASTER_SITES=		http://www.oersted.co.jp/~yav/soft/fkiss/

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.oersted.co.jp/~yav/soft/indexe.html#fkiss
COMMENT=		kisekae viewer

BUILD_DEPENDS+=		autoconf>=2.13:../../devel/autoconf
BUILD_DEPENDS+=		automake>=1.4:../../devel/automake
DEPENDS+=		lha-*:../../archivers/lha

USE_GMAKE=		yes
GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC} && \
		automake && \
		autoreconf --force

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

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
