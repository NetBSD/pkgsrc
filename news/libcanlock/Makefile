# $NetBSD: Makefile,v 1.3 2019/02/13 17:35:08 wiz Exp $

DISTNAME=	libcanlock-3.1.0
CATEGORIES=	news
MASTER_SITES=	http://micha.freeshell.org/libcanlock/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	michael.baeuerle@gmx.net
HOMEPAGE=	http://micha.freeshell.org/libcanlock/
COMMENT=	Standalone RFC 8315 Netnews Cancel-Lock implementation
LICENSE=	mit AND modified-bsd

USE_LANGUAGES+=	c99

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

TEST_TARGET=	test

# Recent NetBSD has a namespace clash with its implementation defined extensions
CFLAGS+=	-D_POSIX_C_SOURCE=200112L

CONFIGURE_ARGS+=	--disable-legacy-api
# The header parsers in the separate news/canlock-hp package
CONFIGURE_ARGS+=	--disable-hp

.include "../../mk/bsd.pkg.mk"
