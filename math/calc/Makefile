# $NetBSD: Makefile,v 1.17 2006/03/04 21:30:03 jlam Exp $

DISTNAME=	calc-2.02f
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=calc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/calc/calc.html
COMMENT=	Advanced Calculator for GNU Emacs

.include "../../mk/emacs.mk"

MAKE_ENV+=	EMACS=${EMACS_FLAVOR:Q}

USE_MAKEINFO=	YES
INFO_FILES=	calc.info

INSTALLATION_DIRS=	info

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/calc
	${INSTALL_DATA} ${WRKSRC}/*.el ${WRKSRC}/*.elc \
	${WRKSRC}/calccard.tex ${EMACS_LISPPREFIX}/calc
	${INSTALL_DATA} ${WRKSRC}/calc.info* ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
