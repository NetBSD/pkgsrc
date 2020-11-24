# $NetBSD: Makefile,v 1.21 2020/11/24 13:52:37 nia Exp $

DISTNAME=	sratom-0.6.6
CATEGORIES=	converters
MASTER_SITES=	https://download.drobilla.net/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://drobilla.net/software/sratom/
COMMENT=	Library for serialising LV2 atoms to/from RDF
LICENSE=	isc

USE_LANGUAGES=	c99
USE_TOOLS+=	gsed pkg-config

PYTHON_FOR_BUILD_ONLY=	tool
PKGCONFIG_OVERRIDE+=	sratom.pc.in

.include "options.mk"
.include "../../devel/waf/waf.mk"
BUILDLINK_API_DEPENDS.sord+=	sord>=0.14.0
.include "../../textproc/sord/buildlink3.mk"
BUILDLINK_API_DEPENDS.serd+=	serd>=0.30.0
.include "../../textproc/serd/buildlink3.mk"
BUILDLINK_API_DEPENDS.lv2+=	lv2>=1.10.0
.include "../../audio/lv2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
