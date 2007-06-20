# $NetBSD: Makefile,v 1.15 2007/06/20 11:49:39 markd Exp $

DISTNAME=	ess-5.3.4
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
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

SUBST_CLASSES+=		etcdir
SUBST_STAGE.etcdir=	pre-patch
SUBST_FILES.etcdir=	lisp/ess-site.el
SUBST_SED.etcdir=	-e 's,"./etc/"),"./etc/" "../../../ess/"),'

INSTALLATION_DIRS=	${EMACS_INFOPREFIX} ${EMACS_LISPPREFIX}/ess
INSTALLATION_DIRS+=	${EMACS_ETCPREFIX}/ess ${EMACS_ETCPREFIX}/ess/icons

do-install:
	cd ${WRKSRC}/lisp && ${INSTALL_DATA} *.el* ${EMACS_LISPPREFIX}/ess
	cd ${WRKSRC}/doc/info; for f in ess.info ess.info-[0-9]*; do	\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${EMACS_INFOPREFIX};		\
        done
	cd ${WRKSRC}/etc && ${INSTALL_DATA} icons/*.xpm ${EMACS_ETCPREFIX}/ess/icons
	cd ${WRKSRC}/etc && ${INSTALL_DATA} *.S ${EMACS_ETCPREFIX}/ess
	cd ${WRKSRC}/etc && ${INSTALL_SCRIPT} ess-sas-sh-command ${EMACS_ETCPREFIX}/ess

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
