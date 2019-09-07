# $NetBSD: Makefile,v 1.8 2019/09/07 14:05:44 fcambus Exp $

DISTNAME=	jo-1.2
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
