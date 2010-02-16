# $NetBSD: Makefile,v 1.1.1.1 2010/02/16 08:56:08 wiz Exp $
#

DISTNAME=	libifp-1.0.0.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ifp-driver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ifp-driver.sourceforge.net/
COMMENT=	General-purpose library-driver for iRiver's iFP portable players
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libusb=${BUILDLINK_PREFIX.libusb}
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
