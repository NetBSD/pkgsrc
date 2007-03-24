# $NetBSD: Makefile,v 1.36 2007/03/24 20:10:08 adam Exp $

DISTNAME=	zsnes151src
PKGNAME=	zsnes-1.51
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

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
