# $NetBSD: Makefile,v 1.14 2005/12/05 20:50:02 rillig Exp $

DISTNAME=	apel-10.6
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/apel/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.kanji.zinbun.kyoto-u.ac.jp/~tomo/elisp/APEL/
COMMENT=	Portable Emacs Library

#CONFLICTS+=	apel-*
#CONFLICTS+=	xemacs-apel-*

PLIST_SRC=	${PKGDIR}/PLIST.${EMACS_FLAVOR}

MAKE_FLAGS+=	EMACS=${EMACS_FLAVOR:Q}
MAKE_FLAGS+=	LISPDIR=${EMACS_LISPPREFIX:Q}
MAKE_FLAGS+=	VERSION_SPECIFIC_LISPDIR=${EMACS_LISPPREFIX:Q}

# apel is included in xemacs-packages
EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox emacs20

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
BUILD_TARGET=	elc
INSTALL_TARGET=	install
.else	# ${EMACS_FLAVOR} == "xemacs"
BUILD_TARGET=	package
INSTALL_TARGET=	install-package
MAKE_FLAGS+=	PACKAGEDIR=${EMACS_LISPPREFIX:C|/lisp$||}
.endif

DOCDIR=		${PREFIX}/share/doc/apel

.if ${EMACS_FLAVOR} == "emacs"
post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.en ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.ja ${DOCDIR}
.endif

.include "../../mk/bsd.pkg.mk"
