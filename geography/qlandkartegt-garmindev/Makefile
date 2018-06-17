# $NetBSD: Makefile,v 1.6 2018/06/17 06:56:30 wiz Exp $

DISTNAME=	garmindev-0.3.4
PKGREVISION=	1
PKGNAME=	qlandkartegt-${DISTNAME}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qlandkartegt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qlandkarte.org/
COMMENT=	Garmin device drivers for qlandkartegt
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

.include "../../mk/libusb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
