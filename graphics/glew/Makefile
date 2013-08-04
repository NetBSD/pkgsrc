# $NetBSD: Makefile,v 1.16 2013/08/04 18:00:52 adam Exp $

DISTNAME=	glew-1.10.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=glew/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://glew.sourceforge.net/
COMMENT=	OpenGL Extension Wrangler Library
LICENSE=	modified-bsd AND mit

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE=	glew.pc.in
MAKEFLAGS+=		CC=${CC:Q} GLEW_DEST=${PREFIX} POPT=${CFLAGS:Q}
MAKEFLAGS+=		LDFLAGS.EXTRA=${X11_LDFLAGS:Q}
INSTALL_TARGET=		install.all
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && !empty(CC:M*gcc*)
MAKEFLAGS+=	SYSTEM=solaris-gcc
.endif

.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
MAKEFLAGS+=	LD=${LD:Q}
.else
MAKEFLAGS+=	LD=${CC:Q}
.endif

pre-configure:
	${LN} -sf Makefile.netbsd ${WRKSRC}/config/Makefile.dragonfly

.include "../../mk/bsd.pkg.mk"
