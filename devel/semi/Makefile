# $NetBSD: Makefile,v 1.3 2002/09/14 02:45:40 uebayasi Exp $

DISTNAME=	semi-1.14.4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/semi/semi-1.14-for-flim-1.14/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.m17n.org/SEMI/
COMMENT=	Emacs lisp library to provide MIME feature

DEPENDS+=	apel-10.*:../../devel/apel
DEPENDS+=	flim-1.*:../../devel/flim

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
