# $NetBSD: Makefile,v 1.4 2025/09/08 09:52:02 vins Exp $

DISTNAME=	telescope-0.11
PKGREVISION=	2
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

CFLAGS.NetBSD+=		-D_OPENBSD_SOURCE			# strtonum()
CFLAGS.SunOS+=		-D__EXTENSIONS__ -D_XOPEN_SOURCE=600	# CMSG_ functions
LDFLAGS.SunOS+=		-lxnet

# Do not warn about deprecated declarations when using OpenSSL 3.x
CFLAGS+=		-Wno-deprecated-declarations

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
