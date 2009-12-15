# $NetBSD: Makefile,v 1.24 2009/12/15 10:29:35 tnn Exp $
#

DISTNAME=	DevIL-${DEVIL_VERSION}
PKGNAME=	${DISTNAME:S/D/d/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openil/}

DEVIL_VERSION=	1.7.8

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openil.sourceforge.net/
COMMENT=	Developer's Image Library

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/devil-${DEVIL_VERSION}
GNU_CONFIGURE=		yes
EXTRACT_USING=		bsdtar
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

INFO_FILES=		yes

CONFIGURE_ARGS+=	--enable-ILU
CONFIGURE_ARGS+=	--enable-ILUT

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
