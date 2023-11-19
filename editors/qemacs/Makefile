# $NetBSD: Makefile,v 1.1 2023/11/19 13:00:26 bacon Exp $

DISTNAME=	qemacs-6.1.1b
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=qemacs/}
GITHUB_TAG=	06b3d373bbcc52b51ccb438bf3cab38a49492ff0
GITHUB_TYPE=	tag

MAINTAINER=	kevin.bloom@posteo.net
HOMEPAGE=	https://github.com/qemacs/qemacs/
COMMENT=	Quick Emacs
LICENSE=	mit

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--enable-plugins
USE_TOOLS+=		gmake

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
