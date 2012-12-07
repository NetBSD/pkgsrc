# $NetBSD: Makefile,v 1.15 2012/12/07 16:01:15 adam Exp $

DISTNAME=	glew-1.9.0
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
MAKE_ENV+=		GLEW_DEST=${PREFIX} X11=${PREFIX} POPT=${CFLAGS:Q}
MAKE_ENV+=		LDFLAGS.EXTRA=${X11_LDFLAGS:Q}
INSTALL_TARGET=		install.all
INSTALLATION_DIRS+=	lib/pkgconfig

post-patch:
	${LN} -sf Makefile.netbsdelf ${WRKSRC}/config/Makefile.dragonfly
	${LN} -sf Makefile.netbsdelf ${WRKSRC}/config/Makefile.netbsd

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && !empty(CC:M*gcc*)
MAKE_ENV+=	SYSTEM=solaris-gcc
.endif

.if ${OPSYS} != "Darwin"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
