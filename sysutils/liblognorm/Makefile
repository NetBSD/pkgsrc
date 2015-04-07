# $NetBSD: Makefile,v 1.3 2015/04/07 14:47:11 fhajny Exp $

DISTNAME=	liblognorm-1.1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.liblognorm.com/files/download/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.liblognorm.com/
COMMENT=	Tool to normalize log data
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	lognorm.pc.in

CONFIGURE_ARGS+=	--disable-docs

.include "../../textproc/json-c/buildlink3.mk"
.include "../../devel/libestr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
