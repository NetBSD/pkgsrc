# $NetBSD: Makefile,v 1.24 2004/10/06 19:35:25 agc Exp $
#

DISTNAME=		imlib2-1.1.2
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.enlightenment.org/pages/imlib2.html
COMMENT=		Image manipulation library

GNU_CONFIGURE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK3=		YES

PKGCONFIG_OVERRIDE=	imlib2.pc.in

LIBS.SunOS=		-lm

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
BUILD_DEFS+=		USE_MMX
. if !empty(USE_MMX:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-mmx
. endif
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/libtool/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
