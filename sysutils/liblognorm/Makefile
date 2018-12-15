# $NetBSD: Makefile,v 1.10 2018/12/15 21:12:23 wiz Exp $

DISTNAME=	liblognorm-2.0.5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.liblognorm.com/files/download/

MAINTAINER=	fhajny@NetBSD.org
HOMEPAGE=	http://www.liblognorm.com/
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
