# $NetBSD: Makefile,v 1.18 2004/04/11 08:32:04 snj Exp $
#

DISTNAME=		zsnes136src
PKGNAME=		zsnes-1.360
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=zsnes/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.zsnes.com/sourceforge.php
COMMENT=		Super NES emulator

BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm

ONLY_FOR_PLATFORM=	*-*-i386

ALL_TARGET=		zsnes

WRKSRC=			${WRKDIR}/zsnes-1.36/src
GNU_CONFIGURE=		# defined
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		# defined
USE_X11=		# defined

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
