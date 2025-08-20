# $NetBSD: Makefile,v 1.2 2025/08/20 11:35:04 wiz Exp $

DISTNAME=	surgescript-0.5.5
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=alemart/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.opensurge2d.org/
COMMENT=	Scripting language for games
LICENSE=	apache-2.0

USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	src/surgescript/misc/surgescript.pc.in

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../mk/bsd.pkg.mk"
