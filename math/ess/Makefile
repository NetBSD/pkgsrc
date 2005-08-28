# $NetBSD: Makefile,v 1.9 2005/08/28 04:25:30 uebayasi Exp $

DISTNAME=	ess-5.1.24
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://software.biostat.washington.edu/ess/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://software.biostat.washington.edu/statsoft/ess/
COMMENT=	Emacs Speaks Statistics

MAKEFLAGS+=	EMACS=${EMACS_BIN}

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
PLIST_SUBST+=	INFODIR=${INFODIR}

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/ess
	cd ${WRKSRC}/lisp && ${INSTALL_DATA} *.el* ${EMACS_LISPPREFIX}/ess
	${INSTALL_DATA} ${WRKSRC}/doc/ess.info* ${PREFIX}/${INFODIR}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
