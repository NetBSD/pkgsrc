# $NetBSD: Makefile,v 1.4 2002/01/29 10:53:41 wiz Exp $
#

DISTNAME=		zsnes1337src
PKGNAME=		zsnes-1.337
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		http://prdownloads.sourceforge.net/zsnes/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.zsnes.com/sourceforge.php
COMMENT=		Super NES emulator

BUILD_DEPENDS+=		nasm-[0-9]*:../../devel/nasm

ONLY_FOR_PLATFORM=	*-*-i386

ALL_TARGET=		zsnes

WRKSRC=			${WRKDIR}/zsnes-1.337/src

GNU_CONFIGURE=		# defined
USE_GMAKE=		# defined
USE_CONFIG_WRAPPER=	# defined
USE_BUILDLINK_ONLY=	# defined

.include "../../devel/SDL/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
