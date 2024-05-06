# $NetBSD: Makefile,v 1.30 2024/05/06 08:40:20 jperkin Exp $

DISTNAME=	alsa-utils-1.2.10
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.alsa-project.org/pub/utils/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.alsa-project.org/
COMMENT=	Advanced Linux Sound Architecture (ALSA) CLI utilities
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake gsed bash:run
USE_PKGLOCALEDIR=	yes
LDFLAGS.DragonFly=	-lm
LDFLAGS.SunOS+=		-lm -lsocket -lnsl
LDFLAGS.Linux+=		-lm -lpthread
LDFLAGS.NetBSD=		-lm -pthread
CPPFLAGS.NetBSD+=	-D__u32=uint32_t -D__u64=uint64_t
CPPFLAGS.NetBSD+=	-Dbswap_16=bswap16 -Dbswap_32=bswap32
CPPFLAGS.NetBSD+=	-Doff64_t=off_t
CPPFLAGS.NetBSD+=	-Dlseek64=lseek

REPLACE_BASH+=		alsaconf/alsaconf.in
REPLACE_BASH+=		alsa-info/alsa-info.sh
REPLACE_BASH+=		bat/alsabat-test.sh

TOOL_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

CONFIGURE_ARGS+=	--disable-nls

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Linux" && defined(OPSYS_HAS_KQUEUE)
CPPFLAGS+=	-I${BUILDLINK_PREFIX.libepoll-shim}/include/libepoll-shim
LDFLAGS+=	-lepoll-shim -linotify
.include "../../devel/libepoll-shim/buildlink3.mk"
.include "../../devel/libinotify/buildlink3.mk"
.endif
.include "../../devel/ncurses/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
