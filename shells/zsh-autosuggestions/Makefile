# $NetBSD: Makefile,v 1.5 2019/11/13 15:24:25 wiz Exp $

DISTNAME=	zsh-autosuggestions-0.6.3
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=zsh-users/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/zsh-users/zsh-autosuggestions
COMMENT=	Fish-like autosuggestions for Zsh
LICENSE=	mit

DEPENDS+=	zsh>=4.3.11:../../shells/zsh

NO_BUILD=	yes
NO_CONFIGURE=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	share/${PKGBASE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/zsh-autosuggestions.zsh \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/

.include "../../mk/bsd.pkg.mk"
