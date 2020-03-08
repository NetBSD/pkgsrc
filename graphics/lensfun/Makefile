# $NetBSD: Makefile,v 1.35 2020/03/08 16:47:48 wiz Exp $

DISTNAME=	lensfun-0.3.2
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lensfun/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://lensfun.github.io/
COMMENT=	Library for rectifying defects introduced by photographic equipment
LICENSE=	gnu-lgpl-v3

USE_CMAKE=		yes
USE_LANGUAGES=		c c++03
USE_TOOLS+=		gmake pkg-config gsed

REPLACE_SH=		apps/g-lensfun-update-data
REPLACE_PYTHON+=	apps/lensfun-add-adapter
REPLACE_PYTHON+=	apps/lensfun-update-data

.include "../../mk/bsd.prefs.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
# png: for test programs only
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
