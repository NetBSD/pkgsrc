# $NetBSD: Makefile,v 1.11 2006/02/05 23:09:43 joerg Exp $
#

DISTNAME=	tc-2.3.1
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
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

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES
INFO_FILES=	tc.info

.include "../../mk/bsd.pkg.mk"
