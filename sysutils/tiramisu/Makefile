# $NetBSD: Makefile,v 1.15 2026/09/27 11:38:45 tnn Exp $

DISTNAME=	tiramisu-2.0.20240610
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Sweets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Sweets/tiramisu/
COMMENT=	Desktop notifications, the UNIX way
LICENSE=	mit

USE_TOOLS+=	pkg-config gmake

MAKE_ENV+=		PREFIX=${PREFIX}

TOOL_DEPENDS+=	vala-[0-9]*:../../lang/vala

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
