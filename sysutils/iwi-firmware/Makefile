# $NetBSD: Makefile,v 1.4 2005/10/03 16:45:08 skrll Exp $
#

DISTNAME=		ipw2200-fw-2.3
PKGNAME=		iwi-firmware-2.3
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://damien.bergamini.free.fr/iwifw/
EXTRACT_SUFX=		.tgz

MAINTAINER=		Damien.Bergamini@Free.FR
HOMEPAGE=		http://damien.bergamini.free.fr/ipw/
COMMENT=		Firmware binary images for iwi(4) driver

LICENSE=		intel-ipw-license


ONLY_FOR_PLATFORM=	NetBSD-*-i386

RESTRICTED=		"Intel Licensed Software: see http://ipw2200.sourceforge.net/firmware.php?fid=5"
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
	${INSTALL_DATA} ${WRKSRC}/ipw-2.3-boot.fw ${PREFIX}/libdata/if_iwi/iwi-boot.fw
	${INSTALL_DATA} ${WRKSRC}/ipw-2.3-bss.fw ${PREFIX}/libdata/if_iwi/iwi-bss.fw
	${INSTALL_DATA} ${WRKSRC}/ipw-2.3-bss_ucode.fw ${PREFIX}/libdata/if_iwi/iwi-ucode-bss.fw
	${INSTALL_DATA} ${WRKSRC}/ipw-2.3-ibss.fw ${PREFIX}/libdata/if_iwi/iwi-ibss.fw
	${INSTALL_DATA} ${WRKSRC}/ipw-2.3-ibss_ucode.fw ${PREFIX}/libdata/if_iwi/iwi-ucode-ibss.fw
	${INSTALL_DATA} ${WRKSRC}/ipw-2.3-sniffer.fw ${PREFIX}/libdata/if_iwi/iwi-sniffer.fw
	${INSTALL_DATA} ${WRKSRC}/ipw-2.3-sniffer_ucode.fw ${PREFIX}/libdata/if_iwi/iwi-ucode-sniffer.fw

.include "../../mk/bsd.pkg.mk"
