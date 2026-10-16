# $NetBSD: Makefile,v 1.3 2026/10/16 21:08:30 schmonz Exp $

DISTNAME=		bash-preexec-0.7.0
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_GITHUB:=rcaloras/}
GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/rcaloras/bash-preexec/
COMMENT=		Preexec and precmd hook functions a la zsh
LICENSE=		mit

USE_LANGUAGES=		# none
NO_BUILD=		yes
INSTALLATION_DIRS=	${PREFIX}/share/${PKGBASE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PKGBASE}.sh ${DESTDIR}${PREFIX}/share/${PKGBASE}/

.include "../../mk/bsd.pkg.mk"
