# $NetBSD: Makefile,v 1.25 2020/03/20 11:57:48 nia Exp $

DISTNAME=	glew-2.1.0
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

.if !empty(PKGSRC_COMPILER:Mgcc) || !empty(PKGSRC_COMPILER:Mclang)
MAKE_ENV.SunOS+=	SYSTEM=solaris-gcc
.endif

.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
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
