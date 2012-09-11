# $NetBSD: Makefile,v 1.6 2012/09/11 23:59:21 asau Exp $
#

DISTNAME=	adplug-2.1
PKGREVISION=	1
CATEGORIES=	audio devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=adplug/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://adplug.sourceforge.net/
COMMENT=	AdLib emulator library supporting many formats

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
INFO_FILES=	yes

PKGCONFIG_OVERRIDE+=	adplug.pc.in

.include "../../devel/libbinio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
