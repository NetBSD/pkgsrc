# $NetBSD: Makefile,v 1.20.10.1 2011/11/12 04:26:38 sbd Exp $

DISTNAME=	ess-5.11
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://ess.r-project.org/downloads/ess/
EXTRACT_SUFX=	.tgz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://ess.r-project.org/
COMMENT=	Emacs Speaks Statistics

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	makeinfo perl
EMACS_MODULES=	base
INFO_FILES=	# PLIST

MAKE_JOBS_SAFE=	no
MAKE_ENV+=	LISPDIR=${EMACS_LISPPREFIX}/ess
MAKEFLAGS+=	EMACS=${EMACS_BIN:Q}

SUBST_CLASSES+=		etcdir
SUBST_STAGE.etcdir=	pre-patch
SUBST_FILES.etcdir=	lisp/ess-site.el
SUBST_SED.etcdir=	-e 's,"./etc/"),"./etc/" "../../../ess/"),'

INSTALLATION_DIRS=	${EMACS_INFOPREFIX} ${EMACS_LISPPREFIX}/ess
INSTALLATION_DIRS+=	${EMACS_ETCPREFIX}/ess ${EMACS_ETCPREFIX}/ess/icons

post-extract:
	cd ${WRKSRC} && chmod u+w doc/*/

do-install:
	cd ${WRKSRC}/lisp && ${INSTALL_DATA} *.el*			\
		${DESTDIR}${EMACS_LISPPREFIX}/ess
	cd ${WRKSRC}/doc/info; for f in ess.info ess.info-[0-9]*; do	\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${EMACS_INFOPREFIX};	\
        done
	cd ${WRKSRC}/etc && ${INSTALL_DATA} icons/*.xpm			\
		${DESTDIR}${EMACS_ETCPREFIX}/ess/icons
	cd ${WRKSRC}/etc && ${INSTALL_DATA} *.S				\
		${DESTDIR}${EMACS_ETCPREFIX}/ess
	cd ${WRKSRC}/etc && ${INSTALL_SCRIPT} ess-sas-sh-command	\
		${DESTDIR}${EMACS_ETCPREFIX}/ess

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
