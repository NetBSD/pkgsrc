# $NetBSD: Makefile,v 1.37 2026/02/06 10:04:37 wiz Exp $

DISTNAME=	ucommon-7.0.0
PKGREVISION=	20
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=commoncpp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/commoncpp/
COMMENT=	Very light-weight C++ library for deeply embedded applications
LICENSE=	gnu-lgpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

# does not support c++17, so force c++11
USE_CXX_FEATURES=	c++11
FORCE_CXX_STD=		c++11

# Incompatible with OpenSSL 1.1
CMAKE_CONFIGURE_ARGS+=	-DCRYPTO_OPENSSL=OFF
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

PKGCONFIG_OVERRIDE+=	commoncpp.pc.in
PKGCONFIG_OVERRIDE+=	ucommon.pc.in

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "options.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
