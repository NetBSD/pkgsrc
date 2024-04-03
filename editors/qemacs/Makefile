# $NetBSD: Makefile,v 1.2 2024/04/03 00:55:28 ktnb Exp $

DISTNAME=	qemacs-6.1.1b
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=qemacs/}
GITHUB_TAG=	06b3d373bbcc52b51ccb438bf3cab38a49492ff0
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
