# $NetBSD: Makefile,v 1.5 2002/02/18 15:14:29 seb Exp $

DISTNAME=	calc-2.02f
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=calc/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/calc/calc.html
COMMENT=	Advanced Calculator for GNU Emacs

.include "../../mk/bsd.prefs.mk"

.if defined(USE_XEMACS)
MAKE_ENV+=	EMACS=xemacs
DEPENDS+=	xemacs-[0-9]*:../../editors/xemacs
SITE_LISP=	lib/xemacs/xemacs-packages/lisp
.else
MAKE_ENV+=	EMACS=emacs
DEPENDS+=	emacs-[0-9]*:../../editors/emacs
SITE_LISP=	share/emacs/site-lisp
.endif

PLIST_SUBST+=	SITE_LISP=${SITE_LISP}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${SITE_LISP}
	${INSTALL_DATA_DIR} ${PREFIX}/${SITE_LISP}/calc
	${INSTALL_DATA} ${WRKSRC}/*.el ${WRKSRC}/*.elc \
	${WRKSRC}/calccard.tex ${PREFIX}/${SITE_LISP}/calc
	${INSTALL_DATA} ${WRKSRC}/calc.info* ${PREFIX}/info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
