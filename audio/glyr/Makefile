# $NetBSD: Makefile,v 1.51 2023/11/08 13:18:05 wiz Exp $
#

DISTNAME=	glyr-1.0.10
PKGREVISION=	36
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=sahib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
