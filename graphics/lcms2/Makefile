# $NetBSD: Makefile,v 1.28 2026/11/01 00:48:37 gdt Exp $

DISTNAME=	lcms2-2.19.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lcms/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.littlecms.com/
COMMENT=	Little Color Management System - a color management library
LICENSE=	mit

# Upstream added cmake support in 2.19, but that has not been declared
# official/favored.  Pending upstream commentary (requested 20260430)
# or some compelling reason, the package will remain on autoconf,
# because the of the usual pattern of cmake build systems having
# regressions from autoconf in various areas, typically cross
# compilation and testing non-installed versions, at least until those
# are assessed.
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	lcms2.pc.in
TEST_TARGET=		check

# Don't switch to cmake yet as upstream has no declared it to be the
# official build system.
#.include "../../devel/cmake/build.mk"

# lcms does not need zlib, but will look for it and link it to tifficc
# if present.  Therefore, we don't enjoin lcms from finding zlib, but
# don't include it via bl3.

.include "../../mk/bsd.prefs.mk"

# lcms2's suballocator defaults to sizeof(void *) alignment; 32-bit
# SPARC needs 8 for doubles (Ghostscript's bundled lcms2mt already
# does this for sparc).  Perhaps other 32-bit arches need this, and if
# so someone(tm) could add a define in mk someplace for "double needs
# more than int alignment, specifically N" and we could use it here;
# this isn't really about lcms.
#
# Upstream declined to add a compile-time conditional to fix this:
#   https://github.com/mm2/Little-CMS/pull/635
.if ${MACHINE_ARCH} == "sparc"
CPPFLAGS+=     -DCMS_PTR_ALIGNMENT=8
.endif

.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
