# $NetBSD: Makefile,v 1.5 2026/10/04 17:37:15 ktnb Exp $

DISTNAME=	qemacs-6.5.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=qemacs/}
GITHUB_TAG=	befd7a816ec824e36bccf3d91c10559bf6752400
GITHUB_TYPE=	tag

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://github.com/qemacs/qemacs/
COMMENT=	Quick Emacs
LICENSE=	mit

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--enable-plugins
USE_TOOLS+=		gmake

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
