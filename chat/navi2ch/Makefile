# $NetBSD: Makefile,v 1.28 2015/03/21 00:36:08 tnn Exp $

DISTNAME=	navi2ch-1.8.4
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=navi2ch/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://navi2ch.sourceforge.net/
COMMENT=	2ch BBS browser for Emacs
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
INFO_FILES=	yes
EMACS_MODULES=	base

# XXX the unit test fails in TZ=CET for some reason
MAKE_ENV+=	TZ=GMT

CONFIGURE_ARGS+=--with-icondir=${PREFIX}/share/navi2ch/icons
CONFIGURE_ARGS+=${CONFIGURE_ARGS.${EMACS_FLAVOR}}

CONFIGURE_ARGS.emacs=	--with-lispdir=${EMACS_LISPPREFIX}/navi2ch
CONFIGURE_ARGS.xemacs=	--with-packagedir=${EMACS_LISPPREFIX:C|/lisp$||}

.include "../../editors/emacs/modules.mk"

.include "../../mk/bsd.pkg.mk"
