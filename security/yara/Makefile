# $NetBSD: Makefile,v 1.3 2017/05/15 15:27:31 khorben Exp $

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
