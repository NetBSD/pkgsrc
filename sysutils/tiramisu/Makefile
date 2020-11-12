# $NetBSD: Makefile,v 1.1 2020/11/12 09:05:13 pin Exp $

DISTNAME=	tiramisu-1.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Sweets/}
#Build from a specific commit until upstream provides a new release
#Patch by Leonardo Taccari upstreamed and merged but, not included
#in the tag release
GITHUB_PROJECT=	tiramisu
GITHUB_TAG=	8eb946dae0e2f98d3850d89e1bb535640e8c3266

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/Sweets/tiramisu/
COMMENT=	Desktop notifications, the UNIX way
LICENSE=	mit

USE_TOOLS+=	pkg-config gmake

INSTALLATION_DIRS+=	share/doc/tiramisu
MAKE_ENV+=		PREFIX=${PREFIX}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/tiramisu

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
