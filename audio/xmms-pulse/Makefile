# $NetBSD: Makefile,v 1.35 2024/01/30 14:21:36 ryoon Exp $

DISTNAME=	xmms-pulse-0.9.4
PKGREVISION=	32
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/xmms-pulse/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	XMMS plugin to output sound through the pulseaudio daemon
HOMEPAGE=	http://0pointer.de/lennart/projects/xmms-pulse/
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-lynx
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
