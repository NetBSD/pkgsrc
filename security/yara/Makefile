# $NetBSD: Makefile,v 1.7 2019/07/11 11:20:06 sevan Exp $

DISTNAME=	yara-${VERSION}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=VirusTotal/}

COMMENT=        Pattern matching swiss knife for malware researchers

USE_TOOLS+=	pkg-config automake autoreconf
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_FEATURES+=	strnlen

PKGCONFIG_OVERRIDE+=	libyara/yara.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../security/openssl/buildlink3.mk"
.include "../../security/yara/Makefile.common"
.include "../../mk/bsd.pkg.mk"
