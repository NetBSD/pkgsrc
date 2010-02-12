# $NetBSD: Makefile,v 1.19 2010/02/12 00:04:36 joerg Exp $

DISTNAME=	jsclasses-071024
PKGNAME=	ja-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	print japanese
MASTER_SITES=	http://oku.edu.mie-u.ac.jp/~okumura/jsclasses/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://oku.edu.mie-u.ac.jp/~okumura/jsclasses/
COMMENT=	New document class files for pLaTeX

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	ja-ptex-bin>=3.1.9:../../print/ja-ptex-bin

WRKSRC=		${WRKDIR}/jsclasses

.include "../../print/teTeX/module.mk"

PLATEX_DIR=	${PKG_LOCALTEXMFPREFIX}/ptex/platex
NO_BUILD=	YES

pre-extract:
	${MKDIR} ${WRKSRC}

post-extract:
	@cd ${WRKSRC}; \
	${MV} ../*.* .

INSTALLATION_DIRS+=	${PLATEX_DIR}/js

do-install:
	@cd ${WRKSRC} && \
	${INSTALL_DATA} *.cls *.dtx *.ins *.sty ${DESTDIR}${PLATEX_DIR}/js

.include "../../mk/bsd.pkg.mk"
