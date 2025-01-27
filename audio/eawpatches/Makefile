# $NetBSD: Makefile,v 1.28 2025/01/27 20:21:13 rillig Exp $
#

DISTNAME=	eawpats12_full
PKGNAME=	eawpatches-12
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/85/}

MAINTAINER=	adam@NetBSD.org
COMMENT=	Eric A. Welsh' patches (audio samples) for TiMidity
LICENSE=	generic-nonlicense

RESTRICTED=		Some patches are copyrighted, some marked no-commercial-use
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
USE_LANGUAGES=		# empty
USE_TOOLS+=		pax
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

INSTALLATION_DIRS=	share

post-extract:
	chmod go-w ${WRKSRC}/eawpats/gravis.cfg

pre-configure:
	sed -e "s@/home/user/eawpats@${PREFIX}/share/eawpats@" \
		< ${WRKSRC}/eawpats/linuxconfig/timidity.cfg \
		> ${WRKSRC}/eawpats/timidity.cfg
	rm -r ${WRKSRC}/eawpats/linuxconfig \
		${WRKSRC}/eawpats/winconfig

do-install:
	cd ${WRKSRC} && pax -wr eawpats ${DESTDIR}${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
