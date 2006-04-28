# $NetBSD: Makefile,v 1.16 2006/04/28 14:30:58 joerg Exp $
#

DISTNAME=	DevIL-1.6.6
PKGNAME=	${DISTNAME:S/D/d/}
PKGREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openil/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openil.sourceforge.net/
COMMENT=	Developer's Image Library

WRKSRC=		${WRKDIR}/DevIL
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--disable-lcms

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
