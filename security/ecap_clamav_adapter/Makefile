# $NetBSD: Makefile,v 1.2 2016/06/23 15:17:28 prlw1 Exp $

DISTNAME=	ecap_clamav_adapter-2.0.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.measurement-factory.com/tmp/ecap/

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://www.e-cap.org/
COMMENT=	eCAP ClamAV adapter
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CXXFLAGS+=	-std=c++11

.include "../../security/clamav/buildlink3.mk"
.include "../../www/libecap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
