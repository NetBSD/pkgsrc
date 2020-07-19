# $NetBSD: Makefile,v 1.11 2020/07/19 07:41:36 fcambus Exp $

DISTNAME=	jo-1.4
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
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
