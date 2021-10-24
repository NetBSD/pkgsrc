# $NetBSD: Makefile,v 1.8 2021/10/24 07:47:41 nia Exp $

DISTNAME=	tiramisu-2.0.20211019
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Sweets/}
GITHUB_PROJECT=	tiramisu
GITHUB_TAG=	2.0-20211019

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Sweets/tiramisu/
COMMENT=	Desktop notifications, the UNIX way
LICENSE=	mit

USE_TOOLS+=	pkg-config gmake

MAKE_ENV+=		PREFIX=${PREFIX}

TOOL_DEPENDS+=	vala-[0-9]*:../../lang/vala

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
