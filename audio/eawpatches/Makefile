# $NetBSD: Makefile,v 1.21 2008/01/21 21:19:41 heinz Exp $
#

DISTNAME=	eawpats12_full
PKGNAME=	eawpatches-12
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=	adam@NetBSD.org
COMMENT=	Eric A. Welsh' patches (audio samples) for TiMidity

RESTRICTED=	Some patches are copyrighted, some marked no-commercial-use
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
LICENSE=		generic-nonlicense

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
USE_LANGUAGES=		# empty
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

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
