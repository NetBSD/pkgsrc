# $NetBSD: Makefile,v 1.35 2020/03/20 11:57:43 nia Exp $

DISTNAME=	plib-1.8.5
PKGREVISION=	5
CATEGORIES=	games x11
MASTER_SITES=	http://plib.sourceforge.net/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://plib.sourceforge.net/
COMMENT=	Libraries for writing portable games/realtime interactive apps
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
CPPFLAGS+=	-Dunix=1

.if ${MACHINE_ARCH} == "x86_64"
CXXFLAGS+=	-fPIC
.endif

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	sl pw

.if ${OPSYS} == "Darwin" && ${ABI} == "64"
CONFIGURE_ARGS+=	--disable-sl \
					--disable-pw
.else
PLIST.sl=		yes
PLIST.pw=		yes
.endif

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
