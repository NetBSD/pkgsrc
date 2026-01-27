# $NetBSD: Makefile,v 1.48 2026/01/27 08:38:59 wiz Exp $

DISTNAME=	libvisual-plugins-0.4.2
PKGREVISION=	1
CATEGORIES=	audio graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=Libvisual/}
GITHUB_PROJECT=	libvisual
GITHUB_RELEASE=	${DISTNAME}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Libvisual/libvisual
COMMENT=	Plugins for libvisual
LICENSE=	gnu-gpl-v2

CONFLICTS=	libvisual-nebulus-[0-9]* libvisual-gforce-[0-9]*

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		mkdirhier pkg-config yacc
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
# required for libGl check
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.endif

.include "../../audio/libvisual/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
