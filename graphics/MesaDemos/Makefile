# $NetBSD: Makefile,v 1.5 2003/04/14 03:46:51 jschauma Exp $

PKGNAME=		MesaDemos-${MESA_VERSION}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		${DISTNAME:S/MesaLib/MesaDemos/}${EXTRACT_SUFX}
WRKSRC=			${WRKDIR}/${DISTNAME:S/Lib//}
MAINTAINER=		jschauma@netbsd.org
COMMENT=		OpenGL examples and Demos

MESA_REQD=		5.0

.include "../Mesa/Makefile.common"

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
BUILD_DIRS=		${WRKSRC}/book ${WRKSRC}/demos ${WRKSRC}/samples
MAKEFILE=		Makefile.X11
ALL_TARGET=		netbsd
MAKE_ENV+=		X11PREFIX=${X11PREFIX}

do-install:
.for dir in book demos images samples
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGNAME}/${dir}
	cd ${WRKSRC}/${dir} && ${PAX} -s ,^./.*Makefile.*,, -s ,^./CVS.*,, \
		-rw . ${PREFIX}/share/examples/${PKGNAME}/${dir}
.endfor
	${CHMOD} -R a+rX ${PREFIX}/share/examples/${PKGNAME}

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
