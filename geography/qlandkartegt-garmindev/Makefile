# $NetBSD: Makefile,v 1.2 2011/01/13 22:34:17 jkunz Exp $
#

DISTNAME=	garmindev-0.3.4
PKGNAME=	qlandkartegt-${DISTNAME}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qlandkartegt/}

MAINTAINER=	jkunz@NetBSD.org
HOMEPAGE=	http://www.qlandkarte.org/
COMMENT=	Garmin device drivers for qlandkartegt
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
