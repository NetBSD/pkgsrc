# $NetBSD: Makefile,v 1.7 2004/01/24 13:42:22 grant Exp $
#

DISTNAME=	tc-2.3
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://openlab.ring.gr.jp/tcode/resources/soft/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/tcode/tc2/index.html
COMMENT=	T-Code driver for Emacs

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "xemacs"
CONFIGURE_ARGS+=--with-emacs=xemacs
CONFIGURE_ARGS+=--with-lispdir=${EMACS_LISPPREFIX}/tc
.endif

USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES
INFO_FILES=	tc.info

.include "../../mk/bsd.pkg.mk"
