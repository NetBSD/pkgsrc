# $NetBSD: Makefile,v 1.4 2017/06/07 20:46:34 wiz Exp $

DISTNAME=	yara-${VERSION}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=VirusTotal/}

COMMENT=        Pattern matching swiss knife for malware researchers

USE_TOOLS+=	pkg-config automake autoreconf
USE_LIBTOOL=	yes
GNU_CONFIGURE=          yes

PKGCONFIG_OVERRIDE+=	libyara/yara.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../security/yara/Makefile.common"
.include "../../mk/bsd.pkg.mk"
