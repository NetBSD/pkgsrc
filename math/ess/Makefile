# $NetBSD: Makefile,v 1.6 2003/08/09 11:11:39 seb Exp $

DISTNAME=	ess-5.1.24
CATEGORIES=	math
MASTER_SITES=	http://software.biostat.washington.edu/ess/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://software.biostat.washington.edu/statsoft/ess/
COMMENT=	Emacs Speaks Statistics

MAKEFLAGS+=	EMACS=${EMACS_BIN}

USE_MAKEINFO=		YES

.if defined(USE_XEMACS)
LISPDIR=	${EMACS_LISPPREFIX}
INFODIR=	${EMACS_LISPPREFIX}/../info
.else
LISPDIR=	${EMACS_LISPPREFIX}
INFODIR=	info
INFO_FILES=	ess.info
.endif

MAKE_ENV+=	LISPDIR=${EMACS_LISPPREFIX}/ess
PLIST_SUBST+=	INFODIR=${INFODIR}
USE_PERL5=	build

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/ess
	cd ${WRKSRC}/lisp && ${INSTALL_DATA} *.el* ${EMACS_LISPPREFIX}/ess
	${INSTALL_DATA} ${WRKSRC}/doc/ess.info* ${PREFIX}/${INFODIR}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
