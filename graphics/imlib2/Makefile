# $NetBSD: Makefile,v 1.1.1.1 2001/08/16 10:49:52 rh Exp $
#

DISTNAME=		imlib2-1.0.3
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.enlightenment.org/pages/imlib2.html
COMMENT=		image manipulation library

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBINTL=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.prefs.mk"

IMLIB2_USE_MMX?=	NO

.if ${MACHINE_ARCH} == "i386" && ${IMLIB2_USE_MMX} != "NO"
CONFIGURE_ARGS+=	--enable-mmx
.endif

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../graphics/freetype-lib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/libungif/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../databases/edb/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
