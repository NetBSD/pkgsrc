# $NetBSD: Makefile,v 1.34 2026/01/07 08:48:13 wiz Exp $

DISTNAME=	ccrtp-2.1.2
PKGREVISION=	23
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=ccrtp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/ccrtp/
COMMENT=	RTP and RTSP protocol implementation using GNU CommonCpp
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	libccrtp.pc.in
INFO_FILES=		yes

CMAKE_CONFIGURE_ARGS+=	-DLIB_VERSION=${PKGVERSION_NOREV}
CMAKE_CONFIGURE_ARGS+=	-DSOVERSION=2
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "options.mk"

.include "../../devel/cmake/build.mk"
BUILDLINK_API_DEPENDS.ucommon+=	ucommon>=6.3.1
.include "../../devel/ucommon/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
