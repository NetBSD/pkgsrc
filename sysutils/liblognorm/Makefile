# $NetBSD: Makefile,v 1.13 2020/05/27 19:37:42 wiz Exp $

DISTNAME=	liblognorm-2.0.6
CATEGORIES=	sysutils
MASTER_SITES=	https://www.liblognorm.com/files/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
