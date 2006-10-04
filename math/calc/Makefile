# $NetBSD: Makefile,v 1.20 2006/10/04 21:47:57 wiz Exp $

DISTNAME=	calc-2.02f
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=calc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://directory.fsf.org/math/calc.html
COMMENT=	Advanced Calculator for GNU Emacs

.include "../../mk/emacs.mk"

MAKE_ENV+=	EMACS=${EMACS_FLAVOR:Q}

USE_TOOLS+=	makeinfo
INFO_FILES=	# PLIST

INSTALLATION_DIRS=	${EMACS_INFOPREFIX} ${EMACS_LISPPREFIX}/calc

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.el ${WRKSRC}/*.elc \
		${WRKSRC}/calccard.tex ${EMACS_LISPPREFIX}/calc
	cd ${WRKSRC}; for f in *.info *.info-[0-9]*; do			\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${EMACS_INFOPREFIX};		\
	done

.include "../../mk/bsd.pkg.mk"
