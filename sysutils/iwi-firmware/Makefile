# $NetBSD: Makefile,v 1.1.1.1 2005/01/11 18:07:53 skrll Exp $
#

DISTNAME=		ipw2200-fw-2.2
PKGNAME=		iwi-firmware-2.2
CATEGORIES=		sysutils
MASTER_SITES=		http://damien.bergamini.free.fr/iwifw/
EXTRACT_SUFX=		.tgz

MAINTAINER=		Damien.Bergamini@Free.FR
HOMEPAGE=		http://damien.bergamini.free.fr/ipw/
COMMENT=		Firmware binary images for iwi(4) driver

LICENSE=		intel-ipw-license

USE_BUILDLINK3=		yes

ONLY_FOR_PLATFORM=	NetBSD-*-i386

RESTRICTED=		"Intel Licensed Software: see http://ipw2200.sourceforge.net/firmware.php?fid=4"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

WRKSRC=			${WRKDIR}

NO_CONFIGURE=		yes
NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libdata/if_iwi
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/libdata/if_iwi
	${INSTALL_DATA} ${WRKSRC}/ipw-2.2-boot.fw ${PREFIX}/libdata/if_iwi/iwi-boot.fw
	${INSTALL_DATA} ${WRKSRC}/ipw-2.2-bss.fw ${PREFIX}/libdata/if_iwi/iwi-bss.fw
	${INSTALL_DATA} ${WRKSRC}/ipw-2.2-bss_ucode.fw ${PREFIX}/libdata/if_iwi/iwi-ucode-bss.fw
	${INSTALL_DATA} ${WRKSRC}/ipw-2.2-ibss.fw ${PREFIX}/libdata/if_iwi/iwi-ibss.fw
	${INSTALL_DATA} ${WRKSRC}/ipw-2.2-ibss_ucode.fw ${PREFIX}/libdata/if_iwi/iwi-ucode-ibss.fw

.include "../../mk/bsd.pkg.mk"
