# $NetBSD: Makefile,v 1.17 2026/06/18 14:43:14 nia Exp $

.include "../../security/yara/Makefile.common"

DISTNAME=	yara-${YARA_VERSION}
CATEGORIES=	security
GITHUB_TAG=	v${YARA_VERSION}

COMMENT=	Pattern matching swiss knife for malware researchers
LICENSE=	modified-bsd

USE_FEATURES+=	strnlen
USE_LIBTOOL=	yes
USE_TOOLS+=	automake autoreconf flex pkg-config
GNU_CONFIGURE=	yes
TEST_TARGET=	check

CFLAGS.SunOS+=	-D__EXTENSIONS__ # getline

PKGCONFIG_OVERRIDE+=	libyara/yara.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
