# $NetBSD: Makefile,v 1.1.1.1 2004/08/27 00:39:23 lukem Exp $

DISTNAME=	ipw2100-fw-1.2
PKGNAME=	ipw-firmware-1.0
CATEGORIES=	net
MASTER_SITES=	http://damien.bergamini.free.fr/ipwfw/
EXTRACT_SUFX=	.tgz

MAINTAINER=	Damien.Bergamini@Free.FR
HOMEPAGE=	http://damien.bergamini.free.fr/ipw/
COMMENT=        Firmware binary images for ipw(4) driver

LICENSE=	intel-ipw-license

WRKSRC=         ${WRKDIR}

ONLY_FOR_PLATFORM=	NetBSD-*-i386

RESTRICTED=		"Intel Licensed Software: see http://ipw2100.sourceforge.net/firmware.php?fid=3"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libdata/if_ipw
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/libdata/if_ipw
	${INSTALL_DATA} ${WRKSRC}/ipw2100-1.2.fw ${PREFIX}/libdata/if_ipw
	${INSTALL_DATA} ${WRKSRC}/ipw2100-1.2-i.fw ${PREFIX}/libdata/if_ipw
	${INSTALL_DATA} ${WRKSRC}/ipw2100-1.2-p.fw ${PREFIX}/libdata/if_ipw
	${INSTALL_DATA} ${FILESDIR}/README ${PREFIX}/libdata/if_ipw

.include "../../mk/bsd.pkg.mk"
