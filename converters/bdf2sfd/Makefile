# $NetBSD: Makefile,v 1.11 2025/08/20 11:34:48 wiz Exp $

DISTNAME=	bdf2sfd-1.1.8
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fcambus/bdf2sfd
COMMENT=	BDF to SFD converter
LICENSE=	2-clause-bsd

USE_CMAKE=	yes

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
