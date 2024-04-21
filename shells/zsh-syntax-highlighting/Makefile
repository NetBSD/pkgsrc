# $NetBSD: Makefile,v 1.2 2024/04/21 15:48:01 wiz Exp $

DISTNAME=	zsh-syntax-highlighting-0.8.0
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
