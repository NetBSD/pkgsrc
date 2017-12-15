# $NetBSD: Makefile,v 1.1 2017/12/15 17:36:38 minskim Exp $

DISTNAME=	zsh-syntax-highlighting-0.6.0
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=zsh-users/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/zsh-users/zsh-syntax-highlighting
COMMENT=	Fish shell like syntax highlighting for Zsh
LICENSE=	modified-bsd

DEPENDS+=	zsh>=4.3.11:../../shells/zsh

NO_BUILD=	yes
NO_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
