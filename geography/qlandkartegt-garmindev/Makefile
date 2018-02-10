# $NetBSD: Makefile,v 1.4 2018/02/10 13:53:48 khorben Exp $
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

.include "../../mk/libusb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
