# $NetBSD: Makefile,v 1.13 2018/01/22 13:27:41 fhajny Exp $

DISTNAME=	jq-1.5
PKGREVISION=	2
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
