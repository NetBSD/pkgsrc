# $NetBSD: Makefile,v 1.1 2017/12/01 01:10:40 minskim Exp $

GITHUB_PROJECT=	pure
DISTNAME=	pure-1.6.0
PKGNAME=	zsh-${DISTNAME}
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=sindresorhus/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/sindresorhus/pure
COMMENT=	Pretty, minimal, and fast Zsh prompt
LICENSE=	mit

DEPENDS+=	zsh-[0-9]*:../../shells/zsh

NO_BUILD=	yes
NO_CONFIGURE=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	share/zsh/site-functions

do-install:
	${INSTALL_DATA} ${WRKSRC}/pure.zsh \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/prompt_pure_setup
	${INSTALL_DATA} ${WRKSRC}/async.zsh \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/async

.include "../../mk/bsd.pkg.mk"
