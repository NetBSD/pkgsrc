# $NetBSD: Makefile,v 1.14.2.1 2018/06/17 12:43:56 spz Exp $

DISTNAME=	jq-1.5
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=stedolan/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/stedolan/jq/
COMMENT=	Command-line JSON processor
LICENSE=	mit

GITHUB_TAG=	${DISTNAME}

USE_LANGUAGES=	c99
USE_LIBTOOL=	yes
USE_TOOLS+=	bison flex gmake
GNU_CONFIGURE=	yes

.include "options.mk"

CFLAGS.SunOS+=	-D_XPG6 -D__EXTENSIONS__

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
