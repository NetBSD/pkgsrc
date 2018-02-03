# $NetBSD: Makefile,v 1.1 2018/02/03 17:28:53 kamil Exp $

DISTNAME=	zenlisp
PKGNAME=	${DISTNAME}-0.0.${ZENLISP_SNAPSHOT}
CATEGORIES=	lang
MASTER_SITES=	http://www.t3x.org/files/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.t3x.org/files/
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
