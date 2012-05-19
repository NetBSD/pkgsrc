# $NetBSD: Makefile,v 1.3 2012/05/19 15:07:46 marino Exp $
#

DISTNAME=		ipw2200-fw-3.0
PKGNAME=		iwi-firmware3-3.0
CATEGORIES=		sysutils
MASTER_SITES=		http://damien.bergamini.free.fr/iwifw/
EXTRACT_SUFX=		.tgz

MAINTAINER=		Damien.Bergamini@Free.FR
HOMEPAGE=		http://damien.bergamini.free.fr/ipw/
COMMENT=		Firmware binary images for iwi(4) driver
LICENSE=		intel-ipw-license

RESTRICTED=		Intel Licensed Software: see http://ipw2200.sourceforge.net/firmware.php?fid=7
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

# http://leaf.dragonflybsd.org/mailarchive/users/2012-05/msg00066.html
NOT_FOR_PLATFORM+=	DragonFly-*-*

CONFLICTS+=		iwi-firmware-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
NO_BUILD=		yes

INSTALLATION_DIRS+=	libdata/if_iwi

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}/${PREFIX}/libdata/if_iwi
	${INSTALL_DATA} ${WRKSRC}/LICENSE.ipw2200-fw ${DESTDIR}/${PREFIX}/libdata/if_iwi/LICENSE
	${INSTALL_DATA} ${WRKSRC}/ipw2200-bss.fw ${DESTDIR}/${PREFIX}/libdata/if_iwi/iwi-bss.fw
	${INSTALL_DATA} ${WRKSRC}/ipw2200-ibss.fw ${DESTDIR}/${PREFIX}/libdata/if_iwi/iwi-ibss.fw
	${INSTALL_DATA} ${WRKSRC}/ipw2200-sniffer.fw ${DESTDIR}/${PREFIX}/libdata/if_iwi/iwi-sniffer.fw

.include "../../mk/bsd.pkg.mk"
