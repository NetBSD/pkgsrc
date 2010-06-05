# $NetBSD: Makefile,v 1.3 2010/06/05 14:45:01 wiz Exp $

DISTNAME=		ocp-0.1.20
CATEGORIES=		audio
MASTER_SITES=		http://stian.cubic.org/ocp/
EXTRACT_SUFX=		.tar.lzma

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://stian.cubic.org/project-ocp.php
COMMENT=		Open Cubic Player
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake makeinfo
USE_LANGUAGES=		c c++
USE_NCURSES=		yes	# resize_term
INFO_FILES=		yes

CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
