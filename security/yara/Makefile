# $NetBSD: Makefile,v 1.15 2024/06/11 10:29:51 adam Exp $

.include "../../security/yara/Makefile.common"

DISTNAME=	yara-${YARA_VERSION}
CATEGORIES=	security

COMMENT=	Pattern matching swiss knife for malware researchers
LICENSE=	modified-bsd

USE_FEATURES+=	strnlen
USE_LIBTOOL=	yes
USE_TOOLS+=	automake autoreconf flex pkg-config
GNU_CONFIGURE=	yes
TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	libyara/yara.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
