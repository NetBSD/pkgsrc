# $NetBSD: Makefile,v 1.4 2002/10/19 06:57:45 minoura Exp $

DISTNAME=	semi-1.14.4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/semi/semi-1.14-for-flim-1.14/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.m17n.org/SEMI/
COMMENT=	Emacs lisp library to provide MIME feature

DEPENDS+=	${PKGNAME_PREFIX}apel-10.*:../../devel/apel
DEPENDS+=	${PKGNAME_PREFIX}flim-1.*:../../devel/flim
BUILD_DEPENDS+=	${PKGNAME_PREFIX}w3-*:../../www/w3

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
ALL_TARGET=     elc
INSTALL_TARGET= install
PLIST_SRC=      ${PKGDIR}/PLIST.emacs
.else   # ${EMACS_FLAVOR} == "xemacs"
ALL_TARGET=     package
INSTALL_TARGET= install-package
PLIST_SRC=      ${PKGDIR}/PLIST.xemacs
MAKEFLAGS+=     PACKAGEDIR=${EMACS_LISPPREFIX:C|/lisp$||}
.endif
DOCDIR=         ${PREFIX}/share/doc/apel

.include "../../mk/bsd.pkg.mk"
