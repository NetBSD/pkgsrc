# $NetBSD: Makefile,v 1.1 2022/11/09 16:58:35 nikita Exp $

DISTNAME=	kona-0.0.0.2021.12.25
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=kevinlawler/}
GITHUB_PROJECT=	kona
GITHUB_TAG=	Win64-20211225

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kevinlawler/kona/
COMMENT=	Interpreter of K, an APL-like programming language
LICENSE=	isc

USE_LANGUAGES=	c
USE_TOOLS=	gmake

INSTALLATION_DIRS=	bin
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
