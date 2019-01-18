# $NetBSD: Makefile,v 1.7 2019/01/18 18:00:54 kamil Exp $

DISTNAME=	jo-1.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jpmens/}

MAINTAINER=	fred@statdns.com
HOMEPAGE=	https://github.com/jpmens/jo
COMMENT=	JSON output from a shell
LICENSE=	gnu-gpl-v2

GITHUB_RELEASE=	${PKGVERSION_NOREV}

GNU_CONFIGURE=	yes

USE_LANGUAGES=	c c99

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
