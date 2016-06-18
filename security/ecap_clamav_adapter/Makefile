# $NetBSD: Makefile,v 1.1 2016/06/18 10:18:57 prlw1 Exp $

DISTNAME=	ecap_clamav_adapter-2.0.0
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

.include "../../security/clamav/buildlink3.mk"
.include "../../www/libecap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
