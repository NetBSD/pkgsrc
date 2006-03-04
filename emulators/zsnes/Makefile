# $NetBSD: Makefile,v 1.31 2006/03/04 21:29:37 jlam Exp $
#

DISTNAME=		zsnes142src
PKGNAME=		zsnes-1.42
PKGREVISION=		3
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
USE_TOOLS+=		gmake

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
