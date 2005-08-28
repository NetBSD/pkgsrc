# $NetBSD: Makefile,v 1.10 2005/08/28 04:25:28 uebayasi Exp $

DISTNAME=	irchat-pj-2.4.24.22
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	chat
MASTER_SITES=	http://irc.fan.gr.jp/pj/src/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://irc.fan.gr.jp/pj/
COMMENT=	Emacs lisp interface to Internet Relay Chat

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
INSTALL_TARGET=	install
.elif ${EMACS_FLAVOR} == "xemacs"
BUILD_TARGET=	package
INSTALL_TARGET=	install-package
.else
PKG_FAIL_REASON+= "Unknown Emacs flavor"
.endif

LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS="${LIBS}"

.include "../../mk/bsd.pkg.mk"
