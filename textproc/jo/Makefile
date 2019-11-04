# $NetBSD: Makefile,v 1.9 2019/11/04 09:24:22 fcambus Exp $

DISTNAME=	jo-1.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jpmens/}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://github.com/jpmens/jo
COMMENT=	JSON output from a shell
LICENSE=	gnu-gpl-v2

GITHUB_RELEASE=	${PKGVERSION_NOREV}

GNU_CONFIGURE=	yes

USE_LANGUAGES=	c c99

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
