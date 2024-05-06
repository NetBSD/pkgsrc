# $NetBSD: Makefile,v 1.19 2024/05/06 08:40:23 jperkin Exp $
#

DISTNAME=		ncc-2.8
PKGREVISION=		12
CATEGORIES=		devel
MASTER_SITES=		http://students.ceid.upatras.gr/~sxanth/ncc/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://students.ceid.upatras.gr/~sxanth/ncc/index.html
COMMENT=		Compiler that produces program analysis information

BUILD_TARGET=		tout
CFLAGS+=		-DNOGNU='"${PREFIX}/share/ncc/nognu"'

USE_LANGUAGES=		c c++

# Fails with C++14 default language
FORCE_CXX_STD=		c++03

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fixing hardcoded paths
SUBST_FILES.prefix=	config.h
SUBST_VARS.prefix=	PREFIX

REPLACE_PYTHON+=	scripts/nccstrip2.py

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/ncc share/doc/ncc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/objdir/ncc ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/nccstrip2.py ${DESTDIR}${PREFIX}/bin
	${LN} -s ncc ${DESTDIR}${PREFIX}/bin/nccar
	${LN} -s ncc ${DESTDIR}${PREFIX}/bin/nccc++
	${LN} -s ncc ${DESTDIR}${PREFIX}/bin/nccld
	${INSTALL_PROGRAM} ${WRKSRC}/nccnav/nccnav ${DESTDIR}${PREFIX}/bin
	${LN} -s nccnav ${DESTDIR}${PREFIX}/bin/nccnavi
	${INSTALL_DATA} ${WRKSRC}/doc/nognu ${DESTDIR}${PREFIX}/share/ncc
	${INSTALL_MAN} ${WRKSRC}/ncc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/KEYS.txt ${DESTDIR}${PREFIX}/share/doc/ncc
	${INSTALL_DATA} ${WRKSRC}/doc/TROUBLES ${DESTDIR}${PREFIX}/share/doc/ncc
	${INSTALL_DATA} ${WRKSRC}/doc/hacking.* ${DESTDIR}${PREFIX}/share/doc/ncc
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/ncc

.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
