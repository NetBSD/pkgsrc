# $NetBSD: Makefile,v 1.25 2022/08/06 07:50:05 nia Exp $

DISTNAME=	alsa-utils-1.2.6
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
USE_NCURSES=		yes
LDFLAGS.DragonFly=	-lm
LDFLAGS.SunOS+=		-lm -lsocket -lnsl
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
CFLAGS+=	-I${BUILDLINK_DIR}/include/libepoll-shim
LDFLAGS+=	-lepoll-shim -linotify
.include "../../devel/libepoll-shim/buildlink3.mk"
.include "../../devel/libinotify/buildlink3.mk"
.endif
.include "../../devel/ncurses/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
