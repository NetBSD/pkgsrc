# $NetBSD: Makefile,v 1.11 2014/05/04 04:29:20 rodent Exp $
#

DISTNAME=	alsa-utils-1.0.22
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

REPLACE_BASH=		alsaconf/alsaconf.in

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

CONFIGURE_ARGS+=	--disable-nls

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
