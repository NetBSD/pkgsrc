# $NetBSD: Makefile,v 1.47 2024/05/29 16:33:46 adam Exp $

DISTNAME=	ogle-0.9.2
PKGREVISION=	18
CATEGORIES=	multimedia
#MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	DVD player with menus
LICENSE=	gnu-gpl-v2

ONLY_FOR_PLATFORM+=	NetBSD-*-i386
ONLY_FOR_PLATFORM+=	NetBSD-*-powerpc
ONLY_FOR_PLATFORM+=	NetBSD-*-alpha
ONLY_FOR_PLATFORM+=	NetBSD-*-sparc64
ONLY_FOR_PLATFORM+=	NetBSD-*-x86_64
ONLY_FOR_PLATFORM+=	Linux-*-*
ONLY_FOR_PLATFORM+=	SunOS-*-* DragonFly-*-*

CPPFLAGS.NetBSD+=	-D_KERNTYPES

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CPPFLAGS=${CPPFLAGS:M*:Q}
#CONFIGURE_ARGS+=	--enable-obsdaudio
#CONFIGURE_ARGS+=	--disable-sunaudio

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-4*)
WRAPPER_TRANSFORM_CMDS+=	opt:-mcpu=pentiumpro:-mtune=pentiumpro
.endif

MESSAGE_SUBST+=		PKGBASE=${PKGBASE}

.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
