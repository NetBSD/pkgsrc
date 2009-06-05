# $NetBSD: Makefile,v 1.35 2009/06/05 11:10:35 wiz Exp $

PKGNAME=	MesaDemos-${MESA_VERSION}
COMMENT=	OpenGL examples and Demos


# We include Makefile.lib here to pull in the configuration machinery.
#
.include "../../graphics/Mesa/Makefile.lib"

USE_TOOLS+=	pax
BUILD_DIRS=	progs
BUILD_TARGET=	default
EGDIR=		${PREFIX}/share/examples/${PKGNAME_NOREV}

AUTO_MKDIRS=	yes

.include "../../graphics/Mesa/buildlink3.mk"

pre-build:
	cd ${WRKSRC} && ${RM} -fr src
	${CP} ${WRKSRC}/configs/pkgsrc ${WRKSRC}/configs/current

do-install:
	cd ${WRKSRC}/progs && pax		\
		-s ',^./.*Makefile.*,,'	\
		-s ',^./CVS.*,,'		\
		-s ',^./.*\.o$$,,'		\
		-s ',^./\.libs.*,,'		\
		-s ',^./\.deps.*,,'		\
		-s ',^./.*\.orig$$,,'		\
		-rw . ${DESTDIR}${EGDIR}/${dir}
	${CHMOD} -R a+rX ${DESTDIR}${EGDIR}

###
### XXX remove this when it's unnecessary
###
post-install:
	${CHMOD} -x ${DESTDIR}${EGDIR}/demos/glslnoise.c
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
