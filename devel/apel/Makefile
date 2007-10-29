# $NetBSD: Makefile,v 1.19 2007/10/29 12:53:51 uebayasi Exp $

DISTNAME=	apel-10.7
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://kanji.zinbun.kyoto-u.ac.jp/~tomo/lemi/dist/apel/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.kanji.zinbun.kyoto-u.ac.jp/~tomo/elisp/APEL/
COMMENT=	Portable Emacs library

PLIST_SRC=	${PKGDIR}/PLIST.${EMACS_FLAVOR}
BUILD_TARGET=	${BUILD_TARGET.${EMACS_FLAVOR}}
INSTALL_TARGET=	${INSTALL_TARGET.${EMACS_FLAVOR}}
MAKE_FLAGS+=	EMACS=${EMACS_FLAVOR:Q}
MAKE_FLAGS+=	LISPDIR=${EMACS_LISPPREFIX:Q}
MAKE_FLAGS+=	VERSION_SPECIFIC_LISPDIR=${EMACS_LISPPREFIX:Q}
MAKE_FLAGS+=	${MAKE_FLAGS.${EMACS_FLAVOR}}
INSTALLATION_DIRS+=	${DOCDIR}

# apel is included in xemacs-packages
EMACS_VERSIONS_ACCEPTED=emacs22 emacs22nox emacs21 emacs21nox emacs20

BUILD_TARGET.emacs=	elc
BUILD_TARGET.xemacs=	package
INSTALL_TARGET.emacs=	install
INSTALL_TARGET.xemacs=	install-package
MAKE_FLAGS.emacs=
MAKE_FLAGS.xemacs=	PACKAGEDIR=${EMACS_LISPPREFIX:C|/lisp$||}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
