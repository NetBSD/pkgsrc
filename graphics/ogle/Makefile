# $NetBSD: Makefile,v 1.25 2003/09/12 20:07:20 grant Exp $

DISTNAME=	ogle-0.9.1
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	DVD player with menus

ONLY_FOR_PLATFORM=	NetBSD-1.5.[23]*-i386 NetBSD-1.5[Y-Z]*-i386
ONLY_FOR_PLATFORM+=	NetBSD-1.[6-9]*-i386 NetBSD-[2-9]*-i386
ONLY_FOR_PLATFORM+=	NetBSD-1.6[D-Z]*-powerpc NetBSD-1.[7-9]*-powerpc
ONLY_FOR_PLATFORM+=	NetBSD-[2-9]*-powerpc

USE_BUILDLINK2=		yes
USE_X11=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
#CONFIGURE_ARGS+=	--enable-obsdaudio
#CONFIGURE_ARGS+=	--disable-sunaudio

USE_GCC2=		# defined

.include "../../audio/liba52/buildlink2.mk"
.include "../../audio/libmad/buildlink2.mk"
.include "../../devel/binutils/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../misc/libdvdread/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
