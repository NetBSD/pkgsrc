# $NetBSD: Makefile,v 1.10 2017/08/03 12:38:22 jperkin Exp $

DISTNAME=	jq-1.5
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=stedolan/}
GITHUB_PROJECT=	jq
GITHUB_TAG=	jq-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/stedolan/jq/
COMMENT=	Command-line JSON processor
LICENSE=	mit

USE_LANGUAGES=	c99
USE_LIBTOOL=	yes
USE_TOOLS+=	bison flex gmake

GNU_CONFIGURE=	yes

CFLAGS.SunOS+=	-D_XPG6 -D__EXTENSIONS__

.include "../../mk/bsd.pkg.mk"
