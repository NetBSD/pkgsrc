# $NetBSD: Makefile,v 1.3 2002/09/13 10:37:53 uebayasi Exp $

DISTNAME=	irchat-pj-2.4.24.20
PKGNAME=	${EMACS_PKGPREFIX}${DISTNAME}
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.madoka.org/pub/irchat-pj/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.fan.gr.jp/~simm/irchat/
COMMENT=	Emacs lisp interface to Internet Relay Chat

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
INSTALL_TARGET=	install
PLIST_SRC=	${PKGDIR}/PLIST.emacs
.elif ${EMACS_FLAVOR} == "xemacs"
ALL_TARGET=	package
INSTALL_TARGET=	install-package
PLIST_SRC=	${PKGDIR}/PLIST.xemacs
.else
IGNORE+=	"Unknown Emacs flavor"
.endif

.include "../../mk/bsd.pkg.mk"
