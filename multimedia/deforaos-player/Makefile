# $NetBSD: Makefile,v 1.2 2013/02/16 11:23:31 wiz Exp $
#

DISTNAME=	Player-0.1.4
PKGNAME=	deforaos-player-0.1.4
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.defora.org/os/download/download/3708/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop media player

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

DEPENDS+=	mplayer-[0-9]*:../../multimedia/mplayer

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "options.mk"

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
