# $NetBSD: Makefile,v 1.2 2004/10/03 00:14:46 tv Exp $
#

DISTNAME=		stratagus-2.1-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=stratagus/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://stratagus.sourceforge.net/
COMMENT=		Real-time strategy engine

WRKSRC=			${WRKDIR}/stratagus-040702
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-flac --with-mad

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stratagus ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/stratagus
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/stratagus/graphics
	${INSTALL_DATA} ${WRKSRC}/doc/*.* ${PREFIX}/share/doc/stratagus
	${INSTALL_DATA} ${WRKSRC}/doc/graphics/* \
		${PREFIX}/share/doc/stratagus/graphics

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libmikmod/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
