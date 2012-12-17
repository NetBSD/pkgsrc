# $NetBSD: Makefile,v 1.14 2012/12/17 13:54:23 drochner Exp $

DISTNAME=		djvulibre-3.5.25.3
PKGNAME=		${DISTNAME:S/-/-lib-/}
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=djvu/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://djvu.sourceforge.net/
COMMENT=		Compression library for scanned documents
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

WRKSRC=			${WRKDIR}/djvulibre-3.5.25
PKGCONFIG_OVERRIDE+=	libdjvu/ddjvuapi.pc.in
BUILD_DIRS=		libdjvu
INSTALL_DIRS=		libdjvu

.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MNetBSD-[5-9]*-i386) && !empty(PKGSRC_COMPILER:Mgcc)
# The library uses Intel atomic intrinsics which don't work with NetBSD's
# default arch setting of "i386" because eg. cmpxchgl is 486+.
# On NetBSD-5+, i386 is desupported so we can safely assume a 486.
CFLAGS+= -march=i486
.endif

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
