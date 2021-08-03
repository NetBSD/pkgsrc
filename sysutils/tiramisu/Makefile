# $NetBSD: Makefile,v 1.4 2021/08/03 17:59:00 pin Exp $

DISTNAME=	tiramisu-2.0alpha
PKGNAME=	tiramisu-2.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Sweets/}
GITHUB_PROJECT=	tiramisu
GITHUB_TAG=	v2.0alpha

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
