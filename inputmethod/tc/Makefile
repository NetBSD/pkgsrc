# $NetBSD: Makefile,v 1.2 2003/04/17 06:00:13 uebayasi Exp $
#

DISTNAME=	tc-2.3
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://openlab.ring.gr.jp/tcode/resources/soft/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
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
INFO_FILES=	tc.info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
