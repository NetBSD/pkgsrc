# $NetBSD: Makefile,v 1.19 2017/08/24 20:03:04 adam Exp $
#

DISTNAME=	glyr-1.0.10
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=sahib/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/sahib/glyr/
COMMENT=	Music related metadata search engine with CLI and C API
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=	pkg-config
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	libglyr.pc.in

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.10
.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
