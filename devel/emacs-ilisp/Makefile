# $NetBSD: Makefile,v 1.2 2002/09/14 03:12:06 uebayasi Exp $
#

DISTNAME=	ilisp-5.11
PKGNAME=	emacs-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ilisp/}

MAINTAINER=	dillo@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/ilisp/
COMMENT=	emacs interface to embedded Lisp process

MAKE_ENV+=	EMACS=${EMACS_BIN}
ALL_TARGET=	compile

.include "../../mk/emacs.mk"

SITELISP=	${EMACS_LISPPREFIX}/ilisp

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
