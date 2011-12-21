# $NetBSD: Makefile,v 1.9 2011/12/21 20:20:43 shattered Exp $

DISTNAME=		ocp-0.1.21
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=opencubicplayer/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shattered@NetBSD.org
HOMEPAGE=		http://sourceforge.net/p/opencubicplayer/
COMMENT=		Open Cubic Player
LICENSE=		gnu-gpl-v2

# uses nested functions
NOT_FOR_COMPILER=	clang

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake makeinfo
USE_LANGUAGES=		c c++
USE_NCURSES=		yes	# resize_term
INFO_FILES=		yes

# ymtype.so wants to link -llzh before it's finished building
MAKE_JOBS_SAFE=		no

CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
