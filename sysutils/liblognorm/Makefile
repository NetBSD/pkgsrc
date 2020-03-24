# $NetBSD: Makefile,v 1.12 2020/03/24 15:59:57 nia Exp $

DISTNAME=	liblognorm-2.0.6
CATEGORIES=	sysutils
MASTER_SITES=	https://www.liblognorm.com/files/download/

MAINTAINER=	fhajny@NetBSD.org
HOMEPAGE=	https://www.liblognorm.com/
COMMENT=	Tool to normalize log data
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	lognorm.pc.in

CONFIGURE_ARGS+=	--disable-docs

.include "../../textproc/libfastjson/buildlink3.mk"
.include "../../devel/libestr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
