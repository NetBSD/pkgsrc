# $NetBSD: Makefile,v 1.26 2004/10/03 00:13:05 tv Exp $

DISTNAME=	flac-1.1.1
PKGREVISION=	1
CATEGORIES=	audio archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=flac/}

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://flac.sourceforge.net/
COMMENT=	Free lossless audio codec

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_XMMS_CONFIG="no"

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386)
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm
.endif

# This version of flac doesn't build with SunPro yet.
NOT_FOR_COMPILER=	sunpro

# This version of flac doesn't seem to build correctly with -O3 using
# the MIPSpro compiler.
.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mmipspro)
BUILDLINK_TRANSFORM+=	rm:-O3
.endif

.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
