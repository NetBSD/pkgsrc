# $NetBSD: Makefile,v 1.3 2024/10/25 15:16:13 ktnb Exp $

DISTNAME=	qemacs-6.3.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=qemacs/}
GITHUB_TAG=	07164c95b96b78e515224b384bd266e612262c6c
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
