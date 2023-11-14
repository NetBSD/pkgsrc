# $NetBSD: Makefile,v 1.53 2023/11/14 14:02:26 wiz Exp $

DISTNAME=	fityk-1.3.2
PKGREVISION=	4
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=wojdyr/}
EXTRACT_SUFX=	.tar.bz2
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fityk.nieto.pl/
COMMENT=	Peak fitting software
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.xylib+=	xylib>=1.6
.include "../../math/xylib/buildlink3.mk"
.include "../../x11/wxGTK32/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
