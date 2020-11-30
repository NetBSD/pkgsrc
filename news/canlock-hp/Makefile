# $NetBSD: Makefile,v 1.5 2020/11/30 11:28:14 micha Exp $

DISTNAME=	libcanlock-3.2.1
PKGNAME=	${DISTNAME:S/libcanlock/canlock-hp/}
CATEGORIES=	news
MASTER_SITES=	http://micha.freeshell.org/libcanlock/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	http://micha.freeshell.org/canlock-hp/
COMMENT=	Parsers for RFC 5536 message headers and RFC 8315 header fields
LICENSE=	mit

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	hp
BUILD_DIRS=	hp

USE_LANGUAGES+=	c99

USE_TOOLS+=	lex yacc

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
