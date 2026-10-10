# $NetBSD: Makefile,v 1.41 2026/10/10 20:45:46 wiz Exp $

DISTNAME=	ess-26.05.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://ess.r-project.org/
DIST_SUBDIR=	${DISTNAME}
DISTFILES=	${DEFAULT_DISTFILES} julia-mode.el julia-mode-latexsubs.el
SITES.julia-mode.el= \
	https://raw.githubusercontent.com/JuliaEditorSupport/julia-emacs/refs/heads/master/
SITES.julia-mode-latexsubs.el= \
	https://raw.githubusercontent.com/JuliaEditorSupport/julia-emacs/refs/heads/master/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ess.r-project.org/
COMMENT=	Emacs Speaks Statistics
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	makeinfo perl gmake
EMACS_MODULES=	base
INFO_FILES=	yes

EMACS_VERSIONS_INCOMPATIBLE=	emacs20 xemacs214 xemacs215 xemacs214nox xemacs215nox

MAKE_JOBS_SAFE=	no
MAKE_ENV+=	LISPDIR=${EMACS_LISPPREFIX}/ess
MAKEFLAGS+=	EMACS=${EMACS_BIN:Q}

INSTALLATION_DIRS=	${EMACS_INFOPREFIX} ${EMACS_LISPPREFIX}/ess
INSTALLATION_DIRS+=	${EMACS_ETCPREFIX}/ess ${EMACS_ETCPREFIX}/ess/icons
INSTALLATION_DIRS+=	${EMACS_ETCPREFIX}/ess/ESSR/R

post-extract:
	${RM} -f ${WRKSRC}/lisp/julia-mode*.el
	cp ${WRKDIR}/julia-mode*.el ${WRKSRC}/lisp/

do-install:
	cd ${WRKSRC}/lisp && ${INSTALL_DATA} *.el*			\
		${DESTDIR}${EMACS_LISPPREFIX}/ess
	rm ${DESTDIR}${EMACS_LISPPREFIX}/ess/*.orig
	cd ${WRKSRC}/doc/info; for f in ess.info ess.info-[0-9]*; do	\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${EMACS_INFOPREFIX};	\
        done
	cd ${WRKSRC}/etc && ${INSTALL_DATA} icons/*.xpm			\
		${DESTDIR}${EMACS_ETCPREFIX}/ess/icons
	cd ${WRKSRC}/etc && ${INSTALL_SCRIPT} ess-julia.jl		\
		${DESTDIR}${EMACS_ETCPREFIX}/ess
	cd ${WRKSRC}/etc && ${INSTALL_SCRIPT} ess-sas-sh-command	\
		${DESTDIR}${EMACS_ETCPREFIX}/ess
	cd ${WRKSRC}/etc/ESSR && ${INSTALL_DATA} BUILDESSR LOADREMOTE	\
		${DESTDIR}${EMACS_ETCPREFIX}/ess/ESSR
	cd ${WRKSRC}/etc/ESSR/R && ${INSTALL_DATA} *.R .*.R		\
		${DESTDIR}${EMACS_ETCPREFIX}/ess/ESSR/R

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
