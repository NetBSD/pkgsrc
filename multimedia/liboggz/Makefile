# $NetBSD: Makefile,v 1.2 2013/06/14 11:09:09 rodent Exp $
#

DISTNAME=	liboggz-1.1.1
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.xiph.org/releases/liboggz/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.xiph.org/oggz/
COMMENT=	Inspects, edits, and validates Ogg files
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	oggz.pc.in

.include "options.mk"

.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-Wl,--version-script=Version_script
.endif

.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
