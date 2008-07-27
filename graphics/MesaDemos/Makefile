# $NetBSD: Makefile,v 1.33 2008/07/27 00:03:42 bjs Exp $

PKGNAME=	MesaDemos-${MESA_VERSION}
COMMENT=	OpenGL examples and Demos

# We include Makefile.lib here to pull in the configuration machinery.
#
.include "../../graphics/Mesa/Makefile.lib"

USE_TOOLS+=	pax
BUILD_DIRS=	progs
BUILD_TARGET=	default
EGDIR=		${PREFIX}/share/examples/${PKGNAME_NOREV}

.include "../../graphics/Mesa/buildlink3.mk"

pre-build:
	cd ${WRKSRC} && ${RM} -fr src
	${CP} ${WRKSRC}/configs/pkgsrc ${WRKSRC}/configs/current
###
### XXX remove this when it's unnecessary
###
pre-install:
	${CHMOD} -x ${DESTDIR}${EGDIR}/demos/glslnoise.c

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}/${dir}
	cd ${WRKSRC}/progs && pax		\
		-s ',^./.*Makefile.*,,'	\
		-s ',^./CVS.*,,'		\
		-s ',^./.*\.o$$,,'		\
		-s ',^./\.libs.*,,'		\
		-s ',^./\.deps.*,,'		\
		-s ',^./.*\.orig$$,,'		\
		-rw . ${DESTDIR}${EGDIR}/${PKGNAME_NOREV}/${dir}
	${CHMOD} -R a+rX ${DESTDIR}${EGDIR}/${PKGNAME_NOREV}

.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
