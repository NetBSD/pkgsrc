# $NetBSD: Makefile,v 1.14 2007/06/11 14:16:25 markd Exp $

DISTNAME=	ess-5.3.4
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://ess.r-project.org/downloads/ess/
EXTRACT_SUFX=	.tgz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://ess.r-project.org/
COMMENT=	Emacs Speaks Statistics

USE_TOOLS+=	makeinfo perl
EMACS_MODULES=	base
INFO_FILES=	# PLIST


MAKE_ENV+=	LISPDIR=${EMACS_LISPPREFIX}/ess
MAKEFLAGS+=	EMACS=${EMACS_BIN:Q}

INSTALLATION_DIRS=	${EMACS_INFOPREFIX} ${EMACS_LISPPREFIX}/ess

do-install:
	cd ${WRKSRC}/lisp && ${INSTALL_DATA} *.el* ${EMACS_LISPPREFIX}/ess
	cd ${WRKSRC}/doc/info; for f in ess.info ess.info-[0-9]*; do	\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${EMACS_INFOPREFIX};		\
        done

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
