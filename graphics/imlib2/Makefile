# $NetBSD: Makefile,v 1.5 2002/12/19 12:45:47 grant Exp $
#

DISTNAME=		imlib2-1.0.3
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.enlightenment.org/pages/imlib2.html
COMMENT=		image manipulation library

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.prefs.mk"

IMLIB2_USE_MMX?=	NO

.if ${MACHINE_ARCH} == "i386" && ${IMLIB2_USE_MMX} != "NO"
CONFIGURE_ARGS+=	--enable-mmx
.endif

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../databases/edb/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
