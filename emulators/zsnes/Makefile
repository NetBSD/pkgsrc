# $NetBSD: Makefile,v 1.46 2015/04/25 14:20:48 tnn Exp $

DISTNAME=	zsnes151src
PKGNAME=	zsnes-1.51
PKGREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zsnes/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zsnes.com/
COMMENT=	Super NES emulator
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm

# Makes heavy use of 32-bit x86 assembler.
ONLY_FOR_PLATFORM=	*-*-i386
# Theoretically we can build a 32-bit binary on amd64 NetBSD, but we'd
# need 32-bit SDL and png and pkgsrc doesn't currently have
# infrastructure for that.
#ONLY_FOR_PLATFORM+=	NetBSD-*-x86_64

WRKSRC=			${WRKDIR}/zsnes_1_51/src
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.3

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
