# $NetBSD: Makefile,v 1.12 2012/05/19 15:06:56 marino Exp $
#

DISTNAME=		ipw2200-fw-2.3
PKGNAME=		iwi-firmware-2.3
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		http://damien.bergamini.free.fr/iwifw/
EXTRACT_SUFX=		.tgz

MAINTAINER=		Damien.Bergamini@Free.FR
HOMEPAGE=		http://damien.bergamini.free.fr/ipw/
COMMENT=		Firmware binary images for iwi(4) driver
LICENSE=		intel-ipw-license

RESTRICTED=		Intel Licensed Software: see http://ipw2200.sourceforge.net/firmware.php?fid=5
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

# http://leaf.dragonflybsd.org/mailarchive/users/2012-05/msg00066.html
NOT_FOR_PLATFORM+=	DragonFly-*-*

CONFLICTS+=		iwi-firmware3-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}

NO_CONFIGURE=		yes
NO_BUILD=		yes

INSTALLATION_DIRS+=	libdata/if_iwi

do-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/libdata/if_iwi
	${INSTALL_DATA} ${WRKSRC}/ipw-2.3-boot.fw ${DESTDIR}${PREFIX}/libdata/if_iwi/iwi-boot.fw
	${INSTALL_DATA} ${WRKSRC}/ipw-2.3-bss.fw ${DESTDIR}${PREFIX}/libdata/if_iwi/iwi-bss.fw
	${INSTALL_DATA} ${WRKSRC}/ipw-2.3-bss_ucode.fw ${DESTDIR}${PREFIX}/libdata/if_iwi/iwi-ucode-bss.fw
	${INSTALL_DATA} ${WRKSRC}/ipw-2.3-ibss.fw ${DESTDIR}${PREFIX}/libdata/if_iwi/iwi-ibss.fw
	${INSTALL_DATA} ${WRKSRC}/ipw-2.3-ibss_ucode.fw ${DESTDIR}${PREFIX}/libdata/if_iwi/iwi-ucode-ibss.fw
	${INSTALL_DATA} ${WRKSRC}/ipw-2.3-sniffer.fw ${DESTDIR}${PREFIX}/libdata/if_iwi/iwi-sniffer.fw
	${INSTALL_DATA} ${WRKSRC}/ipw-2.3-sniffer_ucode.fw ${DESTDIR}${PREFIX}/libdata/if_iwi/iwi-ucode-sniffer.fw

.include "../../mk/bsd.pkg.mk"
