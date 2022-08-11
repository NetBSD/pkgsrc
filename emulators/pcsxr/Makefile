# $NetBSD: Makefile,v 1.6 2022/08/11 05:08:20 gutteridge Exp $

DISTNAME=	pcsxr-1.9.95.20190306
PKGREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=iCatButler/}
GITHUB_PROJECT=	pcsxr
GITHUB_TAG=	62467b86871aee3d70c7445f3cb79f0858ec566e

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/iCatButler/pcsxr
COMMENT=	Sony PlayStation emulator
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CMAKE_ARGS+=	-DDL_LIB=""
.endif

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
NOT_PAX_MPROTECT_SAFE=	bin/pcsxr
.endif

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
