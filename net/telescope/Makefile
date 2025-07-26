# $NetBSD: Makefile,v 1.2 2025/07/26 19:45:58 vins Exp $

DISTNAME=	telescope-0.11
CATEGORIES=	net
MASTER_SITES=	https://ftp.telescope-browser.org/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://telescope-browser.org/
COMMENT=	Multi-protocol browser for the small internet
LICENSE=	isc

USE_TOOLS+=	autoconf automake autoreconf \
		awk pkg-config yacc

USE_CURSES=	wide
FAKE_NCURSES=	yes

CFLAGS.NetBSD+=		-D_OPENBSD_SOURCE   # strtonum()

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	YACC=${YACC:Q}
CONFIGURE_ARGS+=	--with-default-editor=vi

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != OpenBSD
.  include "../../devel/imsg-compat/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libimsg
.endif

.if ${OPSYS} == "Linux"
.  include "../../devel/libbsd/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libbsd
.endif

pre-configure:
	set -e; cd ${WRKSRC} && autoreconf -fiv

.include "../../textproc/libgrapheme/buildlink3.mk"
.include "../../security/libretls/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
