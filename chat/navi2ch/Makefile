# $NetBSD: Makefile,v 1.8 2004/06/26 06:59:39 uebayasi Exp $

DISTNAME=	navi2ch-1.7.3
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=navi2ch/}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://navi2ch.sourceforge.net/
COMMENT=	2ch BBS browser for Emacs

.include "../../mk/emacs.mk"

GNU_CONFIGURE=	# defined
USE_GNU_TOOLS+=	make
.if ${EMACS_FLAVOR} == "emacs"
CONFIGURE_ARGS+=--with-emacs
CONFIGURE_ARGS+=--with-icondir=${PREFIX}/share/navi2ch/icons
CONFIGURE_ARGS+=--with-lispdir=${EMACS_LISPPREFIX}/navi2ch
.else
CONFIGURE_ARGS+=--with-xemacs
CONFIGURE_ARGS+=--with-packagedir=${EMACS_LISPPREFIX}
.endif

INFO_FILES=	navi2ch.info

.include "../../mk/bsd.pkg.mk"
