# $NetBSD: Makefile,v 1.22 2005/05/15 03:13:10 reed Exp $

.include "Makefile.common"
COMMENT=	API for access to scanners, digitals camera, frame grabbers etc.

DISTNAME=       sane-backends-${SANE_VERSION}

BUILD_USES_MSGFMT=	YES
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--with-gphoto2=no

.if (${OPSYS} == "SunOS")
PLIST_SUBST+=	SANE_PINT="@comment "
PLIST_SUBST+=	SANE_SM3600="@comment "
.elif (${OPSYS} == "Linux")
PLIST_SUBST+=	SANE_PINT="@comment "
PLIST_SUBST+=   SANE_SM3600=""
.else
PLIST_SUBST+=	SANE_PINT=""
PLIST_SUBST+=	SANE_SM3600=""
.endif

.if (${OPSYS} != "SunOS")
. include "../../devel/libusb/buildlink3.mk"
.endif
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
