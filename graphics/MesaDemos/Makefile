# $NetBSD: Makefile,v 1.12 2004/01/20 12:18:15 agc Exp $

PKGNAME=		MesaDemos-${MESA_VERSION}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		${DISTNAME:S/MesaLib/MesaDemos/}${EXTRACT_SUFX}
MAINTAINER=		jschauma@NetBSD.org
COMMENT=		OpenGL examples and Demos

PATCHDIR=		${.CURDIR}/patches
DISTINFO_FILE=		${.CURDIR}/distinfo

.include "../Mesa/Makefile.common"

WRKSRC=			${WRKDIR}/${DISTNAME:S/Lib//}
USE_BUILDLINK2=		yes
USE_X11=		yes

MAKE_FLAGS+=		LIB_DEP=""

pre-build:
	${RM} -fr ${WRKSRC}/src

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGNAME_NOREV}/${dir}
	cd ${WRKSRC}/progs && ${PAX} -s ,^./.*Makefile.*,, -s ,^./CVS.*,, \
		-s ,^./.*\\.o$$,, -s ,^./\\.libs.*,, -s ,^./\\.deps.*,,	   \
		-s ,^./.*\\.orig$$,,					\
		-rw . ${PREFIX}/share/examples/${PKGNAME_NOREV}/${dir}
	${CHMOD} -R a+rX ${PREFIX}/share/examples/${PKGNAME_NOREV}

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
