# $NetBSD: Makefile,v 1.2 2008/11/05 12:29:04 wiz Exp $
#

DISTNAME=		ncc-2.8
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://students.ceid.upatras.gr/~sxanth/ncc/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://students.ceid.upatras.gr/~sxanth/ncc/index.html
COMMENT=		Compiler that produces program analysis information

BUILD_TARGET=		tout
CFLAGS+=		-DNOGNU='"${PREFIX}/share/ncc/nognu"'

USE_LANGUAGES=		c c++

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fixing hardcoded paths
SUBST_FILES.prefix=	config.h
SUBST_SED.prefix=	-e 's,@PREFIX@,${PREFIX},g'

PYTHON_PATCH_SCRIPTS+=	scripts/nccstrip2.py

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/objdir/ncc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/nccstrip2.py ${PREFIX}/bin
	${LN} -s ncc ${PREFIX}/bin/nccar
	${LN} -s ncc ${PREFIX}/bin/nccc++
	${LN} -s ncc ${PREFIX}/bin/nccld
	${INSTALL_PROGRAM} ${WRKSRC}/nccnav/nccnav ${PREFIX}/bin
	${LN} -s nccnav ${PREFIX}/bin/nccnavi
	${INSTALL_DATA_DIR} ${PREFIX}/share/ncc
	${INSTALL_DATA} ${WRKSRC}/doc/nognu ${PREFIX}/share/ncc
	${INSTALL_MAN} ${WRKSRC}/ncc.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ncc
	${INSTALL_DATA} ${WRKSRC}/doc/KEYS.txt ${PREFIX}/share/doc/ncc
	${INSTALL_DATA} ${WRKSRC}/doc/TROUBLES ${PREFIX}/share/doc/ncc
	${INSTALL_DATA} ${WRKSRC}/doc/hacking.* ${PREFIX}/share/doc/ncc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ncc

.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
