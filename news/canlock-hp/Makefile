# $NetBSD: Makefile,v 1.1 2018/08/27 15:13:27 wiz Exp $

DISTNAME=	canlock-hp-0.0.3
CATEGORIES=	news
MASTER_SITES=	http://micha.freeshell.org/canlock-hp/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	michael.baeuerle@gmx.net
HOMEPAGE=	http://micha.freeshell.org/canlock-hp/
COMMENT=	Parsers for RFC 5536 message headers and RFC 8315 header fields
LICENSE=	mit

GNU_CONFIGURE=	yes

USE_LANGUAGES+=	c99

USE_TOOLS+=	lex yacc

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
