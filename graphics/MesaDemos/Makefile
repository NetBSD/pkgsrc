# $NetBSD: Makefile,v 1.24 2006/01/19 12:53:17 adam Exp $

PKGNAME=	MesaDemos-${MESA_VERSION}
COMMENT=	OpenGL examples and Demos

PATCHDIR=		${.CURDIR}/patches
DISTINFO_FILE=		${.CURDIR}/distinfo

.include "../../graphics/Mesa/Makefile.common"

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
MAKE_FLAGS+=		LIB_DEP=""

pre-build:
	cd ${WRKSRC} && ${RM} -fr src

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGNAME_NOREV}/${dir}
	cd ${WRKSRC}/progs && ${PAX}		\
		-s ',^./.*Makefile.*,,'	\
		-s ',^./CVS.*,,'		\
		-s ',^./.*\.o$$,,'		\
		-s ',^./\.libs.*,,'		\
		-s ',^./\.deps.*,,'		\
		-s ',^./.*\.orig$$,,'		\
		-rw . ${PREFIX}/share/examples/${PKGNAME_NOREV}/${dir}
	${CHMOD} -R a+rX ${PREFIX}/share/examples/${PKGNAME_NOREV}

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
