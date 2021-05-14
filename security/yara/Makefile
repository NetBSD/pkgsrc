# $NetBSD: Makefile,v 1.10 2021/05/14 11:47:57 nia Exp $

DISTNAME=	yara-${VERSION}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=VirusTotal/}

COMMENT=	Pattern matching swiss knife for malware researchers

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
