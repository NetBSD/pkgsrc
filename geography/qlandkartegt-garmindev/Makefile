# $NetBSD: Makefile,v 1.1 2010/03/02 21:51:06 jkunz Exp $
#

DISTNAME=	garmindev-0.3.3
PKGNAME=	qlandkartegt-${DISTNAME}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qlandkartegt/}

MAINTAINER=	jkunz@NetBSD.org
HOMEPAGE=	http://www.qlandkarte.org/
COMMENT=	Garmin device drivers for qlandkartegt
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/garmindev-0.3.3
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
