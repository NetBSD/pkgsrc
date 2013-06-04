# $NetBSD: Makefile,v 1.5 2013/06/04 22:16:46 tron Exp $
#

DISTNAME=	Player-0.1.5
PKGNAME=	deforaos-player-0.1.5
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.defora.org/os/download/download/4279/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop media player

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

DEPENDS+=	mplayer-[0-9]*:../../multimedia/mplayer

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
AUTO_MKDIRS=	yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/player.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/player.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/playerctl.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/playerctl.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man

.include "options.mk"

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
