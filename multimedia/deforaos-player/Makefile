# $NetBSD: Makefile,v 1.28 2020/04/18 03:56:05 mef Exp $

DISTNAME=	Player-0.2.0
PKGNAME=	deforaos-player-0.2.0
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Player/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop media player

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

DEPENDS+=	mpv-[0-9]*:../../multimedia/mpv

CFLAGS+=	-fPIC

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

post-install:
.if ${PKGMANDIR} != "share/man"
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/player.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/player.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/playerctl.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/playerctl.html
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/player.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/player.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/playerctl.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/playerctl.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/html1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man
.endif

.include "options.mk"

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
