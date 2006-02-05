# $NetBSD: Makefile,v 1.12 2006/02/05 23:08:24 joerg Exp $

DISTNAME=	irchat-pj-2.4.24.22
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
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
MAKE_ENV+=	LIBS=${LIBS:M*:Q}

.include "../../mk/bsd.pkg.mk"
