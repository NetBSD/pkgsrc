# $NetBSD: Makefile,v 1.13 2005/09/28 20:52:18 rillig Exp $

DISTNAME=	navi2ch-1.7.5
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=navi2ch/}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://navi2ch.sourceforge.net/
COMMENT=	2ch BBS browser for Emacs

.include "../../mk/emacs.mk"

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
.if ${EMACS_FLAVOR} == "emacs"
CONFIGURE_ARGS+=--with-emacs
CONFIGURE_ARGS+=--with-lispdir=${EMACS_LISPPREFIX}/navi2ch
.else
CONFIGURE_ARGS+=--with-xemacs
CONFIGURE_ARGS+=--with-packagedir=${EMACS_LISPPREFIX:C|/lisp$||}
.endif
CONFIGURE_ARGS+=--with-icondir=${PREFIX}/share/navi2ch/icons

# XXX	Don't overwrite infodir when XEmacs is used.  In this case infodir
#	must be set by --with-infodir (or --infodir?).  This should be
#	fixed in the original distribution.
SUBST_CLASSES+=		infodir
SUBST_STAGE.infodir=	post-patch
SUBST_MESSAGE.infodir=	Avoid default infodir is overwritten when XEmacs is used
SUBST_FILES.infodir=	configure configure.in
SUBST_SED.infodir=	-e '/infodir=.*packagedir/d'
CONFIGURE_ARGS+=--with-infodir=${PREFIX}/info

INFO_FILES=	navi2ch.info

.include "../../mk/bsd.pkg.mk"
