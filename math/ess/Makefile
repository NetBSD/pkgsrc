# $NetBSD: Makefile,v 1.1.1.1 2003/06/05 11:51:10 markd Exp $

DISTNAME=	ess-5.1.24
CATEGORIES=	math
MASTER_SITES=	http://software.biostat.washington.edu/ess/

MAINTAINER=	markd@netbsd.org
HOMEPAGE=	http://software.biostat.washington.edu/statsoft/ess/
COMMENT=	Emacs Speaks Statistics

MAKEFLAGS+=	EMACS=${EMACS_BIN}

.if defined(USE_XEMACS)
LISPDIR=	${EMACS_LISPPREFIX}
INFODIR=	${EMACS_LISPPREFIX}/../info
.else
LISPDIR=	${EMACS_LISPPREFIX}
INFODIR=	info
INFO_FILES+=	ess.info
.endif

MAKE_ENV+=	LISPDIR=${EMACS_LISPPREFIX}/ess
PLIST_SUBST+=	INFODIR=${INFODIR}

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/ess
	cd ${WRKSRC}/lisp && ${INSTALL_DATA} *.el* ${EMACS_LISPPREFIX}/ess
	${INSTALL_DATA} ${WRKSRC}/doc/ess.info* ${PREFIX}/${INFODIR}

.include "../../mk/emacs.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
