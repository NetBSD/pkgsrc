# $NetBSD: Makefile,v 1.9 2003/11/18 16:10:55 jschauma Exp $

PKGNAME=		MesaDemos-${MESA_VERSION}
PKGREVISION=		1
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		${DISTNAME:S/MesaLib/MesaDemos/}${EXTRACT_SUFX}
WRKSRC=			${WRKDIR}/${DISTNAME:S/Lib//}
MAINTAINER=		jschauma@NetBSD.org
COMMENT=		OpenGL examples and Demos

.include "../Mesa/Makefile.common"

USE_BUILDLINK2=		yes
USE_X11BASE=		yes

BUILD_DIRS=		${WRKSRC}/book ${WRKSRC}/demos ${WRKSRC}/samples
ALL_TARGET=		check
CONFIGURE_ARGS+=	--with-glut=${X11PREFIX}
CONFIGURE_ENV+=		ac_cv_lib_glut_main=yes
MAKE_ENV+=		X11PREFIX=${X11PREFIX}

do-install:
.for dir in book demos images samples
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGNAME_NOREV}/${dir}
	cd ${WRKSRC}/${dir} && ${PAX} -s ,^./.*Makefile.*,, -s ,^./CVS.*,, \
		-s ,^./.*\\.o$$,, -s ,^./\\.libs.*,, -s ,^./\\.deps.*,,	   \
		-rw . ${PREFIX}/share/examples/${PKGNAME_NOREV}/${dir}
.endfor
	${CHMOD} -R a+rX ${PREFIX}/share/examples/${PKGNAME_NOREV}

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
