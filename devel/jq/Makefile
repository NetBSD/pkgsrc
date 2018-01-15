# $NetBSD: Makefile,v 1.12 2018/01/15 08:51:55 adam Exp $

DISTNAME=	jq-1.5
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=stedolan/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/stedolan/jq/
COMMENT=	Command-line JSON processor
LICENSE=	mit

GITHUB_PROJECT=	jq
GITHUB_TAG=	jq-${PKGVERSION_NOREV}

USE_LANGUAGES=	c99
USE_LIBTOOL=	yes
USE_TOOLS+=	bison flex gmake
GNU_CONFIGURE=	yes

CFLAGS.SunOS+=	-D_XPG6 -D__EXTENSIONS__

TEST_TARGET=	check

.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
