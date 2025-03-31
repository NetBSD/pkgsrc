# $NetBSD: Makefile,v 1.4 2025/03/31 17:53:55 ktnb Exp $

DISTNAME=	qemacs-6.4.1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=qemacs/}
GITHUB_TAG=	43b5851958ee13fe0b96cf92b5cfc0aaa085d740
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
