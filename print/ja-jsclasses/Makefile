# $NetBSD: Makefile,v 1.8 2003/07/30 10:41:25 jmmv Exp $

DISTNAME=	jsclasses-030624
PKGNAME=	ja-${DISTNAME}
WRKSRC=		${WRKDIR}/jsclasses
CATEGORIES=	print japanese
MASTER_SITES=	http://www.matsusaka-u.ac.jp/~okumura/jsclasses/
EXTRACT_SUFX=	.zip

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.matsusaka-u.ac.jp/~okumura/jsclasses/
COMMENT=	New document class files for pLaTeX

DEPENDS+=	ja-ptex-bin>=2.1.3:../../print/ja-ptex-bin

USE_PKGINSTALL=	YES

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

.include "../../mk/bsd.pkg.mk"
