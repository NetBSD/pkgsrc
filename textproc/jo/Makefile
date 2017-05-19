# $NetBSD: Makefile,v 1.6 2017/05/19 11:38:36 fhajny Exp $

DISTNAME=	jo-1.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jpmens/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jpmens/jo
COMMENT=	JSON output from a shell
LICENSE=	gnu-gpl-v2

GITHUB_RELEASE=	v${PKGVERSION_NOREV}

GNU_CONFIGURE=	yes

USE_LANGUAGES=	c c99

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
