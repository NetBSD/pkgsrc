# $NetBSD: Makefile,v 1.1.1.1 2001/11/15 20:33:04 dillo Exp $
#

DISTNAME=	ilisp-5.11
PKGNAME=	emacs-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ilisp/}

MAINTAINER=	dillo@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/ilisp/
COMMENT=	emacs interface to embedded Lisp process

DEPENDS+=	emacs-[0-9]*:../../editors/emacs

MAKE_ENV+=	EMACS=${PREFIX}/bin/emacs
ALL_TARGET=	compile

SITELISP=	${PREFIX}/share/emacs/site-lisp/ilisp

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/emacs-ilisp
	${INSTALL_DATA} ${WRKSRC}/INSTALLATION ${PREFIX}/share/doc/emacs-ilisp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/emacs-ilisp
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/emacs-ilisp
	${INSTALL_DATA} ${WRKSRC}/ilisp.emacs \
		${PREFIX}/share/examples/emacs-ilisp
	${INSTALL_DATA_DIR} ${SITELISP}
	${INSTALL_DATA} ${WRKSRC}/*.elc ${SITELISP}
	${INSTALL_DATA} ${WRKSRC}/ild.el ${SITELISP}
	${INSTALL_DATA} ${WRKSRC}/ilisp-imenu.el ${SITELISP}
	${INSTALL_DATA} ${WRKSRC}/ilisp-cl-easy-menu.el ${SITELISP}
	${INSTALL_DATA} ${WRKSRC}/ilisp-scheme-easy-menu.el ${SITELISP}
	${INSTALL_DATA} ${WRKSRC}/*.lisp ${SITELISP}
	${INSTALL_DATA} ${WRKSRC}/*.scm ${SITELISP}
	${INSTALL_DATA_DIR} ${SITELISP}/extra
	${INSTALL_DATA} ${WRKSRC}/extra/hyperspec.elc ${SITELISP}/extra

.include "../../mk/bsd.pkg.mk"
