# $NetBSD: Makefile,v 1.13 2002/09/10 16:06:43 wiz Exp $

DISTNAME=	ogle-0.8.5
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	DVD player with menus

ONLY_FOR_PLATFORM=	NetBSD-1.5.[23]*-i386 NetBSD-1.5[Y-Z]*-i386
ONLY_FOR_PLATFORM+=	NetBSD-1.[6-9]*-i386
ONLY_FOR_PLATFORM+=	NetBSD-1.6[D-Z]*-powerpc NetBSD-1.[7-9]*-powerpc

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
#CONFIGURE_ARGS+=--enable-obsdaudio
#CONFIGURE_ARGS+=--disable-sunaudio

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_BUILDLINK2=		yes
USE_X11=		yes

.include "../../devel/binutils/buildlink2.mk"
.include "../../lang/gcc/Makefile.gcc"

.include "../../audio/liba52/buildlink2.mk"
.include "../../audio/mad/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../misc/libdvdread/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
