# $NetBSD: Makefile,v 1.18 2004/05/03 12:45:58 adam Exp $

.include "Makefile.common"
COMMENT=	API for access to scanners, digitals camera, frame grabbers etc.

DISTNAME=       sane-backends-${SANE_VERSION}

BUILD_USES_MSGFMT=	YES
USE_PKGLOCALEDIR=	YES

.if (${OPSYS} == "SunOS")
PLIST_SUBST+=   NOT_SUNOS="@comment "
.else
PLIST_SUBST+=   NOT_SUNOS=""
.endif

.if (${OPSYS} != "SunOS")
. include "../../devel/libusb/buildlink3.mk"
.endif
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
