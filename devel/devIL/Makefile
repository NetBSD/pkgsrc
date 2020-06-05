# $NetBSD: Makefile,v 1.42 2020/06/05 12:48:59 jperkin Exp $
#

DISTNAME=	DevIL-${DEVIL_VERSION}
PKGNAME=	${DISTNAME:S/D/d/}
PKGREVISION=	15
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openil/}

DEVIL_VERSION=	1.7.8

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openil.sourceforge.net/
COMMENT=	Developer's Image Library
LICENSE=	gnu-lgpl-v2.1

WRKSRC=			${WRKDIR}/devil-${DEVIL_VERSION}
GNU_CONFIGURE=		yes
EXTRACT_USING=		bsdtar
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

INFO_FILES=		yes

CONFIGURE_ARGS+=	--enable-ILU
CONFIGURE_ARGS+=	--enable-ILUT

.include "options.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
