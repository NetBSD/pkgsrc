# $NetBSD: Makefile,v 1.34 2006/05/21 17:09:53 joerg Exp $
#

DISTNAME=		zsnes142src
PKGNAME=		zsnes-1.42
PKGREVISION=		5
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=zsnes/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.zsnes.com/
COMMENT=		Super NES emulator

BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm

ONLY_FOR_PLATFORM=	*-*-i386

BUILD_TARGET=		zsnes

WRKSRC=			${WRKDIR}/zsnes_1_42/src
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
