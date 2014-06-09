# $NetBSD: Makefile,v 1.12 2014/06/09 12:34:26 ryoon Exp $
#

DISTNAME=	alsa-utils-1.0.27.2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.alsa-project.org/pub/utils/
MASTER_SITES+=	ftp://gd.tuwien.ac.at/opsys/linux/alsa/utils/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.alsa-project.org/
COMMENT=	Advanced Linux Sound Architecture (ALSA) CLI utilities

GNU_CONFIGURE=		yes
USE_TOOLS=		pkg-config gmake bash:run
USE_PKGLOCALEDIR=	yes
USE_NCURSES=		yes
LDFLAGS.DragonFly=	-lm
LDFLAGS.SunOS+=		-lm -lsocket -lnsl
CPPFLAGS.NetBSD+=	-D__u32=uint32_t -D__u64=uint64_t
CPPFLAGS.NetBSD+=	-Dbswap_16=bswap16 -Dbswap_32=bswap32

CFLAGS+=		-g

REPLACE_BASH=		alsaconf/alsaconf.in

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

CONFIGURE_ARGS+=	--disable-nls

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
