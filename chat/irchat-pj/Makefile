# $NetBSD: Makefile,v 1.2 2002/12/07 02:38:53 schmonz Exp $

DISTNAME=	irchat-pj-2.4.24.20
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
PKG_FAIL_REASON+= "Unknown Emacs flavor"
.endif

.include "../../mk/bsd.pkg.mk"
