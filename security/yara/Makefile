# $NetBSD: Makefile,v 1.2.16.1 2017/06/13 18:41:37 bsiegert Exp $

PKGNAME=	yara-${YAVER}
CATEGORIES=	security

MASTER_SITES=	${MASTER_SITE_GITHUB:=VirusTotal/yara/archive/}

DIST_SUBDIR=	yara

COMMENT=        Pattern matching swiss knife for malware researchers

WRKSRC=		${WRKDIR}/yara-${YAVER}
USE_TOOLS+=	pkg-config automake autoreconf
USE_LIBTOOL=	yes
GNU_CONFIGURE=          yes

PKGCONFIG_OVERRIDE+=	libyara/yara.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../security/yara/Makefile.common"
.include "../../mk/bsd.pkg.mk"
