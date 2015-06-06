# $NetBSD: Makefile,v 1.2 2015/06/06 08:57:18 pettai Exp $

PKGNAME=	yara-${YAVER}
CATEGORIES=	security

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
