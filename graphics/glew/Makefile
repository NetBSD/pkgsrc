# $NetBSD: Makefile,v 1.19 2015/04/25 14:23:11 tnn Exp $

DISTNAME=	glew-1.11.0
PKGREVISION=	1
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
INSTALL_TARGET=		install.all
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && !empty(CC:M*gcc*)
MAKEFLAGS+=	SYSTEM=solaris-gcc
.endif

.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
MAKEFLAGS+=	LD=${LD:Q}
.else
MAKEFLAGS+=	LD=${CC:Q}
.endif

SUBST_CLASSES+=		x11path
SUBST_MESSAGE.x11path=	Fix X11 path.
SUBST_FILES.x11path=	config/Makefile.*
SUBST_STAGE.x11path=	pre-configure
SUBST_SED.x11path=	-e 's,/usr/X11R[67],${X11BASE},g'

pre-configure:
	${LN} -sf Makefile.netbsd ${WRKSRC}/config/Makefile.dragonfly
	${LN} -sf Makefile.netbsd ${WRKSRC}/config/Makefile.netbsdelf

.include "../../mk/bsd.pkg.mk"
