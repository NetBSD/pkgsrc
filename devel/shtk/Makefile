# $NetBSD: Makefile,v 1.9 2014/11/17 19:55:53 jmmv Exp $

DISTNAME=	shtk-1.6
CATEGORIES=	devel
MASTER_SITES=	https://github.com/jmmv/shtk/releases/download/${DISTNAME}/

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Application toolkit for POSIX-compliant shell scripts
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
TEST_TARGET=		check
USE_LANGUAGES=		# empty
USE_TOOLS=		pkg-config

CONFIGURE_ARGS+=	SHTK_SHELL="${SH}"

.include "../../mk/bsd.pkg.mk"
