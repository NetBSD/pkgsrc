# $NetBSD: Makefile,v 1.16 2015/02/21 23:35:39 ryoon Exp $

DISTNAME=	xmms-pulse-0.9.4
PKGREVISION=	14
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/xmms-pulse/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	XMMS plugin to output sound through the pulseaudio daemon
HOMEPAGE=	http://0pointer.de/lennart/projects/xmms-pulse/

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-lynx
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
