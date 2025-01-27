# $NetBSD: Makefile,v 1.36 2025/01/27 20:21:14 rillig Exp $

DISTNAME=	xmms-pulse-0.9.4
PKGREVISION=	32
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/xmms-pulse/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/xmms-pulse/
COMMENT=	XMMS plugin to output sound through the pulseaudio daemon
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-lynx
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
