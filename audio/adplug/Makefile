# $NetBSD: Makefile,v 1.7 2016/04/20 12:10:24 nros Exp $
#

DISTNAME=	adplug-2.1
PKGREVISION=	1
CATEGORIES=	audio devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=adplug/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://adplug.sourceforge.net/
COMMENT=	AdLib emulator library supporting many formats
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
INFO_FILES=	yes

PKGCONFIG_OVERRIDE+=	adplug.pc.in

.include "../../devel/libbinio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
