# $NetBSD: Makefile,v 1.11 2003/07/31 23:15:47 seb Exp $

DISTNAME=	calc-2.02f
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=calc/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/calc/calc.html
COMMENT=	Advanced Calculator for GNU Emacs

.include "../../mk/emacs.mk"

MAKE_ENV+=	EMACS=${EMACS_FLAVOR}

USE_NEW_TEXINFO=	YES
USE_MAKEINFO=	YES
INFO_FILES=	calc.info

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/calc
	${INSTALL_DATA} ${WRKSRC}/*.el ${WRKSRC}/*.elc \
	${WRKSRC}/calccard.tex ${EMACS_LISPPREFIX}/calc
	${INSTALL_DATA} ${WRKSRC}/calc.info* ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
