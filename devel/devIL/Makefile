# $NetBSD: Makefile,v 1.2 2004/01/03 18:49:37 reed Exp $
#

DISTNAME=	DevIL-1.6.6
PKGNAME=	${DISTNAME:S/D/d/}
PKGREVISION=			1
WRKSRC=		${WRKDIR}/DevIL
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openil/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://openil.sourceforge.net/
COMMENT=	Developer's Image Library

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
USE_X11=		yes

CONFIGURE_ARGS+=	--disable-lcms

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../graphics/mng/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
