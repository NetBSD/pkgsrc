# $NetBSD: Makefile,v 1.13 2022/01/07 21:29:43 fcambus Exp $

DISTNAME=	jo-1.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jpmens/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://github.com/jpmens/jo
COMMENT=	JSON output from a shell
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c99
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	bashcompdir=${PREFIX}/share/bash_completion.d
CONFIGURE_ENV+=	ac_cv_path_PANDOC=none

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
