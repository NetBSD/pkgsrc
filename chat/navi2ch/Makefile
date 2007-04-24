# $NetBSD: Makefile,v 1.19 2007/04/24 15:25:05 uebayasi Exp $

DISTNAME=	navi2ch-cvs_0.0.20070423-1
PKGNAME=	${EMACS_PKGNAME_PREFIX}navi2ch-1.7.5.99.20070423
CATEGORIES=	chat
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=navi2ch/}
MASTER_SITES=	http://navi2ch.sourceforge.net/snapshot/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://navi2ch.sourceforge.net/
COMMENT=	2ch BBS browser for Emacs

WRKSRC=		${WRKDIR}/${DISTNAME:C/cvs_0\.0\./cvs-/:C/-1$//}
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
