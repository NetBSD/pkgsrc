# $NetBSD: Makefile,v 1.19 2004/10/13 18:00:08 tv Exp $

PKGNAME=	MesaDemos-${MESA_VERSION}
PKGREVISION=	2
COMMENT=	OpenGL examples and Demos

PATCHDIR=		${.CURDIR}/patches
DISTINFO_FILE=		${.CURDIR}/distinfo

.include "../Mesa/Makefile.common"

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
MAKE_FLAGS+=		LIB_DEP=""

pre-build:
	cd ${WRKSRC} && ${RM} -fr src

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGNAME_NOREV}/${dir}
	cd ${WRKSRC}/progs && ${PAX} -s ,^./.*Makefile.*,, -s ,^./CVS.*,, \
		-s ,^./.*\\.o$$,, -s ,^./\\.libs.*,, -s ,^./\\.deps.*,,	   \
		-s ,^./.*\\.orig$$,,					\
		-rw . ${PREFIX}/share/examples/${PKGNAME_NOREV}/${dir}
	${CHMOD} -R a+rX ${PREFIX}/share/examples/${PKGNAME_NOREV}

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
