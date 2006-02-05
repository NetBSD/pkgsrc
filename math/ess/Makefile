# $NetBSD: Makefile,v 1.11 2006/02/05 23:10:01 joerg Exp $

DISTNAME=	ess-5.1.24
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://software.biostat.washington.edu/ess/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://software.biostat.washington.edu/statsoft/ess/
COMMENT=	Emacs Speaks Statistics

MAKEFLAGS+=	EMACS=${EMACS_BIN:Q}

USE_MAKEINFO=	YES
USE_TOOLS+=	perl

.if defined(USE_XEMACS)
LISPDIR=	${EMACS_LISPPREFIX}
INFODIR=	${EMACS_LISPPREFIX}/../info
.else
LISPDIR=	${EMACS_LISPPREFIX}
INFODIR=	info
INFO_FILES=	ess.info
.endif
INSTALLATION_DIRS=	${INFODIR}

MAKE_ENV+=	LISPDIR=${EMACS_LISPPREFIX}/ess
PLIST_SUBST+=	INFODIR=${INFODIR:Q}

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/ess
	cd ${WRKSRC}/lisp && ${INSTALL_DATA} *.el* ${EMACS_LISPPREFIX}/ess
	${INSTALL_DATA} ${WRKSRC}/doc/ess.info* ${PREFIX}/${INFODIR}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
