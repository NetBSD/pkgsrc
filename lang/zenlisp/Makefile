# $NetBSD: Makefile,v 1.2 2022/05/15 17:48:57 fcambus Exp $

DISTNAME=	zenlisp
PKGNAME=	${DISTNAME}-0.0.${ZENLISP_SNAPSHOT}
CATEGORIES=	lang
MASTER_SITES=	https://www.t3x.org/files/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.t3x.org/
COMMENT=	Interpreter for symbolic LISP
LICENSE=	happy AND 2-clause-bsd # BSD for src/mexprc/mexprc.l

# zl.c notes VERSION=2, ignore it
ZENLISP_SNAPSHOT=	20131122

WRKSRC=	${WRKDIR}/zenlisp-${ZENLISP_SNAPSHOT}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	BINOWN=${BINOWN}
INSTALL_MAKE_FLAGS+=	BINGRP=${BINGRP}

.include "../../mk/bsd.pkg.mk"
