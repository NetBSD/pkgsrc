# $NetBSD: Makefile,v 1.5 2015/07/31 13:14:20 ryoon Exp $

DISTNAME=	jq-jq-1.4
PKGNAME=	${DISTNAME:S/jq-jq-/jq-/}
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
USE_TOOLS+=	autoconf automake autoreconf bison flex gmake

GNU_CONFIGURE=	yes

CFLAGS.SunOS+=	-D_XPG6

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../mk/bsd.pkg.mk"
