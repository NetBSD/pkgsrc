# $NetBSD: Makefile,v 1.5 2011/11/25 22:45:00 joerg Exp $
#

DISTNAME=	adplug-2.1
PKGREVISION=	1
CATEGORIES=	audio devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=adplug/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://adplug.sourceforge.net/
COMMENT=	AdLib emulator library supporting many formats

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
INFO_FILES=	yes

PKGCONFIG_OVERRIDE+=	adplug.pc.in

.include "../../devel/libbinio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
