# $NetBSD: Makefile,v 1.3 2012/10/04 09:19:20 asau Exp $
#

DISTNAME=	garmindev-0.3.4
PKGNAME=	qlandkartegt-${DISTNAME}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qlandkartegt/}

MAINTAINER=	jkunz@NetBSD.org
HOMEPAGE=	http://www.qlandkarte.org/
COMMENT=	Garmin device drivers for qlandkartegt
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
