# $NetBSD: Makefile,v 1.1.1.1 2002/10/28 18:40:22 uebayasi Exp $

DISTNAME=	navi2ch-1.6.0
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/navi2ch}

MAINTAINER=	uebayasi@netbsd.org
HOMEPAGE=	http://navi2ch.sourceforge.net/
COMMENT=	2ch BBS browser for Emacs

.include "../../mk/emacs.mk"

GNU_CONFIGURE=	# defined
.if ${EMACS_FLAVOR} == "emacs"
CONFIGURE_ARGS+=--with-emacs
CONFIGURE_ARGS+=--with-icondir=${PREFIX}/share/navi2ch/icons
CONFIGURE_ARGS+=--with-lispdir=${EMACS_LISPPREFIX}/navi2ch
.else
CONFIGURE_ARGS+=--with-xemacs
CONFIGURE_ARGS+=--with-packagedir=${EMACS_LISPPREFIX}
.endif
USE_GMAKE=	# defined

INFO_FILES=	navi2ch.info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
