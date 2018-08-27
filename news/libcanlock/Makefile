# $NetBSD: Makefile,v 1.1 2018/08/27 15:14:03 wiz Exp $

DISTNAME=	libcanlock-3.0.2
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

.include "../../mk/bsd.pkg.mk"
