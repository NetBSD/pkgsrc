# $NetBSD: Makefile,v 1.11 2015/03/11 19:39:57 tnn Exp $

DISTNAME=	shtk-1.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jmmv/}
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Application toolkit for POSIX-compliant shell scripts
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
TEST_TARGET=		check
USE_LANGUAGES=		# empty
USE_TOOLS=		pkg-config

CONFIGURE_ARGS+=	SHTK_SHELL="${SH}"

.include "../../mk/bsd.pkg.mk"
