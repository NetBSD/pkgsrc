# $NetBSD: Makefile,v 1.11 2003/05/05 16:24:01 jmmv Exp $
#

DISTNAME=		zsnes136src
PKGREVISION=		1
PKGNAME=		zsnes-1.360
WRKSRC=			${WRKDIR}/zsnes-1.36/src
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=zsnes/}

MAINTAINER=		packages@netbsd.org
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
