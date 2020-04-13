# $NetBSD: Makefile,v 1.23 2020/04/13 19:11:31 joerg Exp $
#

DISTNAME=	ilisp-20021222
PKGNAME=	${EMACS_PKGNAME_PREFIX}emacs-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ilisp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/ilisp/
COMMENT=	Emacs interface to embedded Lisp process
#LICENSE=	# ILISP License, see COPYING file.

EMACS_VERSIONS_ACCEPTED= emacs20 emacs21 emacs21nox

MAKE_ENV+=	EMACS=${EMACS_BIN:Q}
BUILD_TARGET=	compile

SITELISP=	${EMACS_LISPPREFIX}/ilisp

SUBST_CLASSES+=			string-to-int
SUBST_STAGE.string-to-int=	pre-configure
SUBST_MESSAGE.string-to-int=	obsolete function (as of 22.1); use `string-to-number' instead
SUBST_FILES.string-to-int+=	ilisp-acl.el
SUBST_SED.string-to-int=	-e 's/string-to-int/string-to-number/'

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/emacs-ilisp
	${INSTALL_DATA} ${WRKSRC}/INSTALLATION \
		${DESTDIR}${PREFIX}/share/doc/emacs-ilisp
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/emacs-ilisp
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/emacs-ilisp
	${INSTALL_DATA} ${WRKSRC}/ilisp.emacs \
		${DESTDIR}${PREFIX}/share/examples/emacs-ilisp
	${INSTALL_DATA_DIR} ${DESTDIR}${SITELISP}
	${INSTALL_DATA} ${WRKSRC}/*.el ${DESTDIR}${SITELISP}
	${INSTALL_DATA} ${WRKSRC}/*.elc ${DESTDIR}${SITELISP}
	${INSTALL_DATA} ${WRKSRC}/*.lisp ${DESTDIR}${SITELISP}
	${INSTALL_DATA} ${WRKSRC}/*.scm ${DESTDIR}${SITELISP}
	${INSTALL_DATA_DIR} ${DESTDIR}${SITELISP}/extra
	${INSTALL_DATA} ${WRKSRC}/extra/*.el ${DESTDIR}${SITELISP}/extra
	${INSTALL_DATA} ${WRKSRC}/extra/*.elc ${DESTDIR}${SITELISP}/extra

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
