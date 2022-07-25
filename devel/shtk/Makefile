# $NetBSD: Makefile,v 1.13 2022/07/25 11:12:24 wiz Exp $

DISTNAME=	shtk-1.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jmmv/}
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Application toolkit for POSIX-compliant shell scripts
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
TEST_TARGET=		check
USE_LANGUAGES=		# empty

CONFIGURE_ARGS+=	SHTK_SHELL="${SH}"

.include "../../mk/bsd.pkg.mk"
