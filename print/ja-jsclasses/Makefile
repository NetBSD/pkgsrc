# $NetBSD: Makefile,v 1.2 2003/03/29 12:42:15 jmmv Exp $

DISTNAME=	jsclasses
PKGNAME=	ja-jsclasses-0.0.0.20021127
WRKSRC=		${WRKDIR}/jsclasses
CATEGORIES=	print japanese
MASTER_SITES=	http://www.matsusaka-u.ac.jp/~okumura/jsclasses/
EXTRACT_SUFX=	.lzh

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://www.matsusaka-u.ac.jp/~okumura/jsclasses/
COMMENT=	new document class files for pLaTeX

DEPENDS+=	ja-ptex-bin>=2.1.3:../../print/ja-ptex-bin
BUILD_DEPENDS+=	ack>=1.39:../../converters/ack

PLATEX_DIR=	${PREFIX}/share/texmf.local/ptex/platex
NO_BUILD=	YES

pre-extract:
	${MKDIR} ${WRKSRC}

post-extract:
	@cd ${WRKSRC}; \
	${MV} ../*.* .; \
	${PREFIX}/bin/ack -AeS *.cls *.dtx *.ins *.sty; \
	${RM} *.bak

do-install:
	@cd ${WRKSRC}; \
	${INSTALL_DATA_DIR} ${PLATEX_DIR}/js; \
	${INSTALL_DATA} *.cls *.dtx *.ins *.sty ${PLATEX_DIR}/js

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
