# $NetBSD: Makefile,v 1.1 2022/12/14 19:10:45 nikita Exp $

DISTNAME=	es-0.9.2
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=wryun/}
GITHUB_PROJECT=	es-shell
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wryun.github.io/es-shell/
COMMENT=	Resurection of es shell
LICENSE=	public-domain

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c
GNU_CONFIGURE=	yes
BUILD_TARGET=	es
CONFIGURE_ENV=	es_cv_abused_getenv=no

# INSTALL says this can be build with editline or readline,
# configure does not seem to support this anymore.
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
