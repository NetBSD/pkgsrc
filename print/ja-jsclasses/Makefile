# $NetBSD: Makefile,v 1.4 2003/06/15 11:34:52 kei Exp $

DISTNAME=	jsclasses
PKGNAME=	ja-jsclasses-0.0.0.20030529
WRKSRC=		${WRKDIR}/jsclasses
CATEGORIES=	print japanese
MASTER_SITES=	http://www.matsusaka-u.ac.jp/~okumura/jsclasses/
EXTRACT_SUFX=	.zip

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://www.matsusaka-u.ac.jp/~okumura/jsclasses/
COMMENT=	new document class files for pLaTeX

DEPENDS+=	ja-ptex-bin>=2.1.3:../../print/ja-ptex-bin

PLATEX_DIR=	${PREFIX}/share/texmf.local/ptex/platex
NO_BUILD=	YES

pre-extract:
	${MKDIR} ${WRKSRC}

post-extract:
	@cd ${WRKSRC}; \
	${MV} ../*.* .

do-install:
	@cd ${WRKSRC}; \
	${INSTALL_DATA_DIR} ${PLATEX_DIR}/js; \
	${INSTALL_DATA} *.cls *.dtx *.ins *.sty ${PLATEX_DIR}/js

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
