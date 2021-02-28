# $NetBSD: Makefile,v 1.1 2021/02/28 08:06:52 nia Exp $

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

.include "../../mk/bsd.pkg.mk"
