# $NetBSD: Makefile,v 1.23 2005/01/20 00:43:15 xtraeme Exp $
#

DISTNAME=		zsnes141src
PKGNAME=		zsnes-1.41
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=zsnes/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.zsnes.com/
COMMENT=		Super NES emulator

BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm

ONLY_FOR_PLATFORM=	*-*-i386

BUILD_TARGET=		zsnes

WRKSRC=			${WRKDIR}/zsnes_1_41/src
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes
USE_X11=		yes

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
