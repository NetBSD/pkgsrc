# $NetBSD: Makefile,v 1.5 2003/07/21 16:43:20 martti Exp $
#

DISTNAME=	ilisp-20021222
PKGNAME=	emacs-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ilisp/}

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/ilisp/
COMMENT=	Emacs interface to embedded Lisp process

MAKE_ENV+=	EMACS=${EMACS_BIN}
ALL_TARGET=	compile

SITELISP=	${EMACS_LISPPREFIX}/ilisp

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/emacs-ilisp
	${INSTALL_DATA} ${WRKSRC}/INSTALLATION ${PREFIX}/share/doc/emacs-ilisp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/emacs-ilisp
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/emacs-ilisp
	${INSTALL_DATA} ${WRKSRC}/ilisp.emacs \
		${PREFIX}/share/examples/emacs-ilisp
	${INSTALL_DATA_DIR} ${SITELISP}
	${INSTALL_DATA} ${WRKSRC}/*.el* ${SITELISP}
	${INSTALL_DATA} ${WRKSRC}/*.lisp ${SITELISP}
	${INSTALL_DATA} ${WRKSRC}/*.scm ${SITELISP}
	${INSTALL_DATA_DIR} ${SITELISP}/extra
	${INSTALL_DATA} ${WRKSRC}/extra/*.el* ${SITELISP}/extra

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
