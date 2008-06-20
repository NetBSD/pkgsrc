# $NetBSD: Makefile,v 1.13 2008/06/20 01:09:23 joerg Exp $
#

DISTNAME=	tc-2.3.1
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	2
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://openlab.ring.gr.jp/tcode/resources/soft/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/tcode/tc2/index.html
COMMENT=	T-Code driver for Emacs

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "xemacs"
CONFIGURE_ARGS+=--with-emacs=xemacs
CONFIGURE_ARGS+=--with-lispdir=${EMACS_LISPPREFIX}/tc
.endif

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES
INFO_FILES=	# PLIST

.include "../../mk/bsd.pkg.mk"
