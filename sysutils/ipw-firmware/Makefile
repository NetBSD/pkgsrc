# $NetBSD: Makefile,v 1.7 2009/05/19 08:59:34 wiz Exp $

DISTNAME=	ipw2100-fw-1.2
PKGNAME=	ipw-firmware-1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://damien.bergamini.free.fr/ipwfw/
EXTRACT_SUFX=	.tgz

MAINTAINER=	Damien.Bergamini@Free.FR
HOMEPAGE=	http://damien.bergamini.free.fr/ipw/
COMMENT=	Firmware binary images for ipw(4) driver
LICENSE=	intel-ipw-license

RESTRICTED=		Intel Licensed Software: see http://ipw2100.sourceforge.net/firmware.php?fid=3
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	libdata/if_ipw

do-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/libdata/if_ipw
	${INSTALL_DATA} ${WRKSRC}/ipw2100-1.2.fw ${DESTDIR}${PREFIX}/libdata/if_ipw
	${INSTALL_DATA} ${WRKSRC}/ipw2100-1.2-i.fw ${DESTDIR}${PREFIX}/libdata/if_ipw
	${INSTALL_DATA} ${WRKSRC}/ipw2100-1.2-p.fw ${DESTDIR}${PREFIX}/libdata/if_ipw
	${INSTALL_DATA} ${FILESDIR}/README ${DESTDIR}${PREFIX}/libdata/if_ipw

.include "../../mk/bsd.pkg.mk"
