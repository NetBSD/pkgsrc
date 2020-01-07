# $NetBSD: Makefile,v 1.4 2020/01/07 12:15:13 micha Exp $

DISTNAME=	libcanlock-3.1.1
CATEGORIES=	news
MASTER_SITES=	http://micha.freeshell.org/libcanlock/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	micha@NetBSD.org
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
