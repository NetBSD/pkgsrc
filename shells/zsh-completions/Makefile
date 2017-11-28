# $NetBSD: Makefile,v 1.1 2017/11/28 19:31:44 minskim Exp $

DISTNAME=	zsh-completions-0.27.0
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=zsh-users/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/zsh-users/zsh-completions
COMMENT=	Additional completion definitions for zsh
LICENSE=	zsh

DEPENDS+=	zsh-[0-9]*:../../shells/zsh

NO_BUILD=	yes
NO_CONFIGURE=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	share/zsh/site-functions

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/* \
		${DESTDIR}${PREFIX}/share/zsh/site-functions

.include "../../mk/bsd.pkg.mk"
