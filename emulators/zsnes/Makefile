# $NetBSD: Makefile,v 1.14 2003/07/17 21:36:33 grant Exp $
#

DISTNAME=		zsnes136src
PKGNAME=		zsnes-1.360
PKGREVISION=		1
WRKSRC=			${WRKDIR}/zsnes-1.36/src
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=zsnes/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.zsnes.com/sourceforge.php
COMMENT=		Super NES emulator

BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm

ONLY_FOR_PLATFORM=	*-*-i386

ALL_TARGET=		zsnes

GNU_CONFIGURE=		# defined
USE_GMAKE=		# defined
USE_BUILDLINK2=		# defined
USE_X11=		# defined

.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
