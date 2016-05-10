# $NetBSD: Makefile,v 1.7 2016/05/10 09:20:52 tnn Exp $

DISTNAME=	jq-1.5
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=stedolan/}
GITHUB_PROJECT=	jq
GITHUB_TAG=	jq-${PKGVERSION_NOREV}

MAINTAINER=	jperkin@joyent.com
HOMEPAGE=	http://github.com/stedolan/jq/
COMMENT=	Command-line JSON processor
LICENSE=	mit

USE_LANGUAGES=	c99
USE_LIBTOOL=	yes
USE_TOOLS+=	bison flex gmake

GNU_CONFIGURE=	yes

CFLAGS.SunOS+=	-D_XPG6

.include "../../mk/bsd.pkg.mk"
