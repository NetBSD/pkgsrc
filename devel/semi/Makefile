# $NetBSD: Makefile,v 1.5 2003/01/11 15:21:19 uebayasi Exp $

DISTNAME=	semi-1.14.5
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/semi/semi-1.14-for-flim-1.14/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.m17n.org/SEMI/
COMMENT=	Emacs lisp library to provide MIME feature

DEPENDS+=	apel>=10.3:../../devel/apel
DEPENDS+=	flim>=1.6:../../devel/flim
#BUILD_DEPENDS+=	w3-[0-9]*:../../www/w3

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
ALL_TARGET=     elc
INSTALL_TARGET= install
#PLIST_SRC=      ${PKGDIR}/PLIST.emacs
.else   # ${EMACS_FLAVOR} == "xemacs"
ALL_TARGET=     package
INSTALL_TARGET= install-package
#PLIST_SRC=      ${PKGDIR}/PLIST.xemacs
MAKEFLAGS+=     PACKAGEDIR=${EMACS_LISPPREFIX:C|/lisp$||}
.endif
DOCDIR=         ${PREFIX}/share/doc/apel

.include "../../mk/bsd.pkg.mk"
