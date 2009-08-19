# $NetBSD: Makefile,v 1.17 2009/08/19 00:54:29 uwe Exp $
#

DISTNAME=	ilisp-20021222
PKGNAME=	${EMACS_PKGNAME_PREFIX}emacs-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ilisp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/ilisp/
COMMENT=	Emacs interface to embedded Lisp process

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=	EMACS=${EMACS_BIN:Q}
BUILD_TARGET=	compile

SITELISP=	${EMACS_LISPPREFIX}/ilisp

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
