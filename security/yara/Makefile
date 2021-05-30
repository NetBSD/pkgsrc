# $NetBSD: Makefile,v 1.11 2021/05/30 01:16:28 khorben Exp $

DISTNAME=	yara-${YARA_VERSION}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=VirusTotal/}

COMMENT=	Pattern matching swiss knife for malware researchers
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config automake autoreconf flex
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_FEATURES+=	strnlen

PKGCONFIG_OVERRIDE+=	libyara/yara.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../security/openssl/buildlink3.mk"
.include "../../security/yara/Makefile.common"
.include "../../mk/bsd.pkg.mk"
