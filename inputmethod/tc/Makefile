# $NetBSD: Makefile,v 1.4 2003/08/07 11:59:29 seb Exp $
#

DISTNAME=	tc-2.3
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://openlab.ring.gr.jp/tcode/resources/soft/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/tcode/tc2/index.html
COMMENT=	T-Code driver for Emacs

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
.elif ${EMACS_FLAVOR} == "xemacs"
CONFIGURE_ARGS+=--with-emacs=xemacs
CONFIGURE_ARGS+=--with-lispdir=${EMACS_LISPPREFIX}/tc
.endif

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
USE_NEW_TEXINFO=	YES
INFO_FILES=	tc.info

.include "../../mk/bsd.pkg.mk"
