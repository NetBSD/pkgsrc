# $NetBSD: Makefile,v 1.17 2004/03/20 22:19:56 bouyer Exp $

.include "Makefile.common"
COMMENT=	API for access to scanners, digitals camera, frame grabbers etc.

DISTNAME=       sane-backends-${SANE_VERSION}
PKGREVISION=	1

SANE_MICRO=	12

USE_PKGLOCALEDIR=	YES
BUILD_USES_MSGFMT=	YES

.if (${OPSYS} == "SunOS")
PLIST_SUBST+=   NOT_SUNOS="@comment "
.else
PLIST_SUBST+=   NOT_SUNOS=""
.endif

.if (${OPSYS} != "SunOS")
. include "../../devel/libusb/buildlink2.mk"
.endif
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
