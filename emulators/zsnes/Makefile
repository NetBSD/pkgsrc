# $NetBSD: Makefile,v 1.29 2005/12/11 09:40:40 wiz Exp $
#

DISTNAME=		zsnes142src
PKGNAME=		zsnes-1.42
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=zsnes/}

MAINTAINER=		tech-pkg@NetBSD.org
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
