# $NetBSD: Makefile,v 1.3 2002/09/14 02:44:36 uebayasi Exp $

DISTNAME=	apel-10.3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/apel/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.kanji.zinbun.kyoto-u.ac.jp/~tomo/elisp/APEL/
COMMENT=	Portable Emacs Library

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
ALL_TARGET=	elc
INSTALL_TARGET=	install
PLIST_SRC=	${PKGDIR}/PLIST.emacs
.else	# ${EMACS_FLAVOR} == "xemacs"
ALL_TARGET=	package
INSTALL_TARGET=	install-package
PLIST_SRC=	${PKGDIR}/PLIST.xemacs
MAKEFLAGS+=	PACKAGEDIR=${EMACS_LISPPREFIX:C|/lisp$||}
.endif

DOCDIR=		${PREFIX}/share/doc/apel

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.en ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.ja ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
