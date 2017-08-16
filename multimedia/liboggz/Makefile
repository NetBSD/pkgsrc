# $NetBSD: Makefile,v 1.7 2017/08/16 20:21:12 wiz Exp $
#

DISTNAME=	liboggz-1.1.1
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.xiph.org/releases/liboggz/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://www.xiph.org/oggz/
COMMENT=	Inspects, edits, and validates Ogg files
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	oggz.pc.in

.include "options.mk"

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=Version_script

.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
