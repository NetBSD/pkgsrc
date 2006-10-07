# $NetBSD: Makefile,v 1.17 2006/10/07 06:12:42 uebayasi Exp $

DISTNAME=	navi2ch-1.7.5
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	4
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=navi2ch/}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://navi2ch.sourceforge.net/
COMMENT=	2ch BBS browser for Emacs

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
INFO_FILES=	# PLIST
EMACS_MODULES=	base

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
CONFIGURE_ARGS+=	--with-emacs
CONFIGURE_ARGS+=	--with-lispdir=${EMACS_LISPPREFIX}/navi2ch
.elif ${EMACS_FLAVOR} == "xemacs"
CONFIGURE_ARGS+=	--with-xemacs
CONFIGURE_ARGS+=	--with-packagedir=${EMACS_LISPPREFIX:C|/lisp$||}
.endif
CONFIGURE_ARGS+=	--with-icondir=${PREFIX}/share/navi2ch/icons

.include "../../mk/bsd.pkg.mk"
