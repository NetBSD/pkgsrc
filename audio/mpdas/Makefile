# $NetBSD: Makefile,v 1.36 2021/12/08 16:03:17 adam Exp $
#

DISTNAME=		mpdas-0.4.5
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://50hz.ws/mpdas/

MAINTAINER=		gls@NetBSD.org
HOMEPAGE=		https://50hz.ws/mpdas/
COMMENT=		AudioScrobbler client for MPD written in C++
LICENSE=		modified-bsd

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c++03

MAKE_FLAGS+=		MANPREFIX="${PREFIX}/${PKGMANDIR}/man1"

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${DOCDIR} ${EGDIR}
RCD_SCRIPTS=		mpdas
DOCDIR=			share/doc/mpdas
EGDIR=			share/examples/mpdas

CONF_FILES+=		${EGDIR}/mpdasrc.example \
				${PKG_SYSCONFDIR}/mpdasrc

post-install:
	${INSTALL_DATA}	${WRKSRC}/README \
		${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA}	${WRKSRC}/mpdasrc.example \
		${DESTDIR}${PREFIX}/${EGDIR}

.include "../../audio/libmpdclient/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
