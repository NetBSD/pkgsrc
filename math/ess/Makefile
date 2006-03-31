# $NetBSD: Makefile,v 1.13 2006/03/31 04:29:51 jlam Exp $

DISTNAME=	ess-5.1.24
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://software.biostat.washington.edu/ess/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://software.biostat.washington.edu/statsoft/ess/
COMMENT=	Emacs Speaks Statistics

USE_TOOLS+=	makeinfo perl
EMACS_MODULES=	base

MAKE_ENV+=	LISPDIR=${EMACS_LISPPREFIX}/ess
MAKEFLAGS+=	EMACS=${EMACS_BIN:Q}

INSTALLATION_DIRS=	${EMACS_INFOPREFIX} ${EMACS_LISPPREFIX}/ess

do-install:
	cd ${WRKSRC}/lisp && ${INSTALL_DATA} *.el* ${EMACS_LISPPREFIX}/ess
	cd ${WRKSRC}/doc; for f in ess.info ess.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${EMACS_INFOPREFIX};		\
        done

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
