# $NetBSD: Makefile,v 1.1 2024/01/30 09:00:40 wiz Exp $

COMMITS=	225
DISTNAME=	sonic-0.0.0.${COMMITS}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=waywardgeek/}
GITHUB_TAG=	8694c596378c24e340c09ff2cd47c065494233f1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/waywardgeek/sonic
COMMENT=	Simple library to speed up or slow down speech
LICENSE=	apache-2.0

USE_LANGUAGES=		c
USE_TOOLS=		gmake
CFLAGS+=		-Wall -Wno-unused-function -ansi -fPIC -pthread
CFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib
MAKE_FLAGS+=		PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
