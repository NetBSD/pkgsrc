# $NetBSD: Makefile,v 1.5 2004/03/14 08:19:18 uebayasi Exp $

DISTNAME=	irchat-pj-2.4.24.22
CATEGORIES=	chat
MASTER_SITES=	http://irc.fan.gr.jp/pj/src/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://irc.fan.gr.jp/pj/
COMMENT=	Emacs lisp interface to Internet Relay Chat

USE_BUILDLINK3=	yes

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
INSTALL_TARGET=	install
.elif ${EMACS_FLAVOR} == "xemacs"
ALL_TARGET=	package
INSTALL_TARGET=	install-package
.else
PKG_FAIL_REASON+= "Unknown Emacs flavor"
.endif

.include "../../mk/bsd.pkg.mk"
