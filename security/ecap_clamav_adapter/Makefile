# $NetBSD: Makefile,v 1.7 2020/06/02 08:24:39 adam Exp $

DISTNAME=	ecap_clamav_adapter-2.0.0
PKGREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://www.measurement-factory.com/tmp/ecap/

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://www.e-cap.org/
COMMENT=	eCAP ClamAV adapter
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++11
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../security/clamav/buildlink3.mk"
.include "../../www/libecap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
