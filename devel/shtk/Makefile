# $NetBSD: Makefile,v 1.10 2015/03/07 14:31:03 tnn Exp $

DISTNAME=	shtk-1.6
CATEGORIES=	devel
USE_GITHUB=	yes
GH_ACCOUNT=	jmmv
GH_RELEASE=	${DISTNAME}

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Application toolkit for POSIX-compliant shell scripts
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
TEST_TARGET=		check
USE_LANGUAGES=		# empty
USE_TOOLS=		pkg-config

CONFIGURE_ARGS+=	SHTK_SHELL="${SH}"

.include "../../mk/bsd.pkg.mk"
