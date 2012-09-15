# $NetBSD: Makefile,v 1.9 2012/09/15 10:03:46 obache Exp $

DISTNAME=	xmms-pulse-0.9.4
PKGREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/xmms-pulse/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	XMMS plugin to output sound through the pulseaudio daemon
HOMEPAGE=	http://0pointer.de/lennart/projects/xmms-pulse/

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-lynx
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
