# $NetBSD: Makefile,v 1.7 2003/09/01 14:51:00 minoura Exp $

DISTNAME=	apel-10.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/apel/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.kanji.zinbun.kyoto-u.ac.jp/~tomo/elisp/APEL/
COMMENT=	Portable Emacs Library

#CONFLICTS+=	apel-*
#CONFLICTS+=	xemacs-apel-*

MAKE_FLAGS+=	EMACS=${EMACS_FLAVOR}
MAKE_FLAGS+=	LISPDIR=${EMACS_LISPPREFIX}
MAKE_FLAGS+=	VERSION_SPECIFIC_LISPDIR=${EMACS_LISPPREFIX}

EMACS_VERSIONS_ACCEPTED=	emacs21 emacs20 xemacs214 xemacs215

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
ALL_TARGET=	elc
INSTALL_TARGET=	install
PLIST_SRC=	${PKGDIR}/PLIST.emacs
.else	# ${EMACS_FLAVOR} == "xemacs"
ALL_TARGET=
INSTALL_TARGET=	install-package
PLIST_SRC=	${PKGDIR}/PLIST.xemacs
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
