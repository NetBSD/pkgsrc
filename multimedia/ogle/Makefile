# $NetBSD: Makefile,v 1.19 2006/07/16 22:20:37 seb Exp $

DISTNAME=	ogle-0.9.2
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	DVD player with menus

ONLY_FOR_PLATFORM=	NetBSD-1.5.[23]*-i386 NetBSD-1.5[Y-Z]*-i386
ONLY_FOR_PLATFORM+=	NetBSD-1.6*-i386 NetBSD-[2-9]*-i386
ONLY_FOR_PLATFORM+=	NetBSD-1.6[D-Z]*-powerpc
ONLY_FOR_PLATFORM+=	NetBSD-[2-9]*-powerpc
ONLY_FOR_PLATFORM+=	NetBSD-1.6Z*-alpha NetBSD-[2-9]*-alpha
ONLY_FOR_PLATFORM+=	NetBSD-1.6Z*-sparc64 NetBSD-[2-9]*-sparc64
ONLY_FOR_PLATFORM+=	NetBSD-*-x86_64
ONLY_FOR_PLATFORM+=	Linux-*-*
ONLY_FOR_PLATFORM+=	SunOS-*-* DragonFly-*-*

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CPPFLAGS=${CPPFLAGS:M*:Q}
#CONFIGURE_ARGS+=	--enable-obsdaudio
#CONFIGURE_ARGS+=	--disable-sunaudio

GCC_REQD+=		2.95.3

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-4*)
WRAPPER_TRANSFORM_CMDS+=	opt:-mcpu=pentiumpro:-march=pentiumpro
.endif

MESSAGE_SUBST+=		PKGBASE=${PKGBASE}

.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../devel/binutils/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
