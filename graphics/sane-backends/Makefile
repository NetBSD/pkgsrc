# $NetBSD: Makefile,v 1.20 2004/10/03 00:14:57 tv Exp $

.include "Makefile.common"
COMMENT=	API for access to scanners, digitals camera, frame grabbers etc.

DISTNAME=       sane-backends-${SANE_VERSION}
PKGREVISION=	1

BUILD_USES_MSGFMT=	YES
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--with-gphoto2=no

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
