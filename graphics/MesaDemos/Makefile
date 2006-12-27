# $NetBSD: Makefile,v 1.29 2006/12/27 13:37:38 joerg Exp $

PKGNAME=	MesaDemos-${MESA_VERSION}
COMMENT=	OpenGL examples and Demos

# We include Makefile.lib instead of Makefile.common since we actually
# build the Mesa libraries as part of the build process, even though we
# don't install them.
#
.include "../../graphics/Mesa/Makefile.lib"

PATCHDIR=	${.CURDIR}/patches
DISTINFO_FILE=	${.CURDIR}/distinfo

USE_TOOLS+=	gmake
MAKE_FLAGS+=	LIB_DEP=""

.include "../../graphics/Mesa/buildlink3.mk"

pre-build:
	cd ${WRKSRC} && ${RM} -fr src

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/${PKGNAME_NOREV}/${dir}
	cd ${WRKSRC}/progs && ${PAX}		\
		-s ',^./.*Makefile.*,,'	\
		-s ',^./CVS.*,,'		\
		-s ',^./.*\.o$$,,'		\
		-s ',^./\.libs.*,,'		\
		-s ',^./\.deps.*,,'		\
		-s ',^./.*\.orig$$,,'		\
		-rw . ${DESTDIR}${PREFIX}/share/examples/${PKGNAME_NOREV}/${dir}
	${CHMOD} -R a+rX ${DESTDIR}${PREFIX}/share/examples/${PKGNAME_NOREV}

.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
