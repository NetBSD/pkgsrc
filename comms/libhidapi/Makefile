# $NetBSD: Makefile,v 1.2 2015/04/03 22:36:02 rodent Exp $

GITHUB_PROJECT=	hidapi
GITHUB_TAG=	${GITHUB_PROJECT}-0.7.0
DISTNAME=	${GITHUB_TAG}
PKGNAME=	lib${DISTNAME}
CATEGORIES=	comms devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=signal11/}

MAINTAINER=	nathanialsloss@yahoo.com.au
HOMEPAGE=	http://www.signal11.us/oss/hidapi/
COMMENT=	Library for comunicating with bluetooth and usb hid devices
LICENSE=	gnu-gpl-v3 OR modified-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

NO_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}
INSTALLATION_DIRS+=	include/${GITHUB_PROJECT} lib

.include "../../mk/bsd.fast.prefs.mk"

CFLAGS+=		-fPIC

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
