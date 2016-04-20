# $NetBSD: Makefile,v 1.19 2016/04/20 12:10:24 nros Exp $

DISTNAME=	alsa-utils-1.1.1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.alsa-project.org/pub/utils/
MASTER_SITES+=	ftp://gd.tuwien.ac.at/opsys/linux/alsa/utils/
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

CFLAGS+=		-g

REPLACE_BASH+=		alsaconf/alsaconf.in
REPLACE_BASH+=		alsa-info/alsa-info.sh
REPLACE_BASH+=		bat/alsabat-test.sh

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

CONFIGURE_ARGS+=	--disable-nls

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
