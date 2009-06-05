# $NetBSD: Makefile,v 1.76 2009/06/05 11:10:35 wiz Exp $

PKGNAME=	MesaLib-${MESA_PKGVERSION}
COMMENT=	Graphics library similar to SGI's OpenGL

MESA_HEADERS=	gl.h gl_mangle.h glext.h glx.h glxext.h	\
		glx_mangle.h osmesa.h xmesa.h xmesa_x.h	\
 		xmesa_xf86.h

MESA_HEADERS+=	internal/dri_interface.h internal/sarea.h

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEFS+=		MESA_HZ
PLIST_VARS=		dri nodri

.include "glx-config.mk"
.include "../../graphics/Mesa/Makefile.lib"
.include "options.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-[12].*)
##
## NetBSD 2.x and earlier require pthread stubs
##
.  include "../../devel/pthread-stublib/buildlink3.mk"
PTHREAD_STUBLIB= -L${PREFIX}/lib -Wl,-R${PREFIX}/lib -lpthstub
.elif !empty(MACHINE_PLATFORM:MNetBSD-*)
##
## NetBSD 3.x and later have pthread stubs in libc
##
PTHREAD_STUBLIB=
.else
##
## Other platforms may or may not have stubs provided by libc, but pulling in
## threading support via the pthread.buildlink3.mk definitions will provide
## all the necessary interfaces.  This matches the standard configuration for
## most platforms as they appear in "${WRKSRC}/configs", and is necessary
## for successful linking with libGL under many platforms.
##
.include "../../mk/pthread.buildlink3.mk"
PTHREAD_STUBLIB= ${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}
.endif
PKGSRC_MAKE_ENV+=	PTHREAD_STUBLIB=${PTHREAD_STUBLIB:Q}

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
MAKE_ENV+=	CROSS_COMPILING=yes
.endif

RM_PATCH_BACKUP_DIRS=	docs src/mesa src/glut/glx \
			progs/demos progs/xdemos progs/glsl
post-extract:
	${CP} ${FILESDIR}/gen_matypes.awk ${WRKSRC}/src/mesa/x86
	${CP} ${FILESDIR}/gen_matypes.sh ${WRKSRC}/src/mesa/x86
	${CHMOD} a+x ${WRKSRC}/src/mesa/x86/gen_matypes.sh
	for fn in ${RM_PATCH_BACKUP_DIRS}; do \
		${RM} -f ${WRKSRC}/$${fn}/*.orig; \
	done

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/GL/internal

pre-build:
	cd ${WRKSRC} && ${RM} -fr src/glu src/glut progs

.include "../../mk/bsd.pkg.mk"
