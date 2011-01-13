# $NetBSD: Makefile,v 1.40 2011/01/13 13:37:37 wiz Exp $

DISTNAME=	zsnes151src
PKGNAME=	zsnes-1.51
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zsnes/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zsnes.com/
COMMENT=	Super NES emulator

BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm

ONLY_FOR_PLATFORM=	*-*-i386

WRKSRC=			${WRKDIR}/zsnes_1_51/src
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
LDFLAGS+=		${COMPILER_RPATH_FLAG}${LOCALBASE}/lib

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.3

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
