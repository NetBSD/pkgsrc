# $NetBSD: Makefile,v 1.60 2008/04/30 16:40:08 bjs Exp $

PKGNAME=	MesaLib-${MESA_PKGVERSION}
COMMENT=	Graphics library similar to SGI's OpenGL

MESA_HEADERS=	gl.h gl_mangle.h glext.h glx.h glxext.h	\
		glx_mangle.h osmesa.h xmesa.h xmesa_x.h	\
 		xmesa_xf86.h

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEFS+=		MESA_HZ MESA_EXECMEM_HEAPSIZE

.include "../../mk/bsd.prefs.mk"

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

.if (${MACHINE_ARCH} == "x86_64" || \
    ${MACHINE_ARCH} == "sparc64" || \
    ${MACHINE_ARCH} == "alpha")
CFLAGS+=	-D__GLX_ALIGN64
.endif

.if !empty(MACHINE_ARCH:Mi386)
###
### This is taken from <sys/arch/i386/include/npx.h>.  If we don't override
### it, the FPU control word will be restored to 0x037f.
###
### Also, see patch-aq about the libm functions required (float functions
### such as floorf).  Proper configuration of this should be a goal of
### the Mesa developers; alas, it obviously is not.
###
### XXX We need a reliable check for these functions.
###
#/* NetBSD uses IEEE double precision. */
CFLAGS.NetBSD+=		-DDEFAULT_X86_FPU=0x127f
###
###
#/* FreeBSD leaves some exceptions unmasked as well. */
###
CFLAGS.FreeBSD+=	-DDEFAULT_x86_FPU=0x1272
.endif

CFLAGS.FreeBSD+=	-DUSE_NATIVE_LIBM_FUNCS
CFLAGS.FreeBSD+=	-DUSE_SSE_SYSCTL_DETECTION

CFLAGS.Linux+=		-DUSE_NATIVE_LIBM_FUNCS

CFLAGS.NetBSD+=		-DUSE_NATIVE_LIBM_FUNCS
CFLAGS.NetBSD+=		-DUSE_SSE_SYSCTL_DETECTION

CFLAGS.DragonFly+=	-DUSE_NATIVE_LIBM_FUNCS
CFLAGS.DragonFly+=	-DUSE_SSE_SYSCTL_DETECTION

PLIST_VARS=		dri nodri

.include "../../graphics/Mesa/Makefile.lib"
.include "options.mk"
.include "../../mk/pthread.buildlink3.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-[12].*)
.  include "../../devel/pthread-stublib/buildlink3.mk"
PTHREAD_STUBLIB= "-L${PREFIX}/lib -Wl,-R${PREFIX}/lib -lpthstub"
.else
PTHREAD_STUBLIB= # provided by libc
.endif
PKGSRC_MAKE_ENV+=	PTHREAD_STUBLIB=${PTHREAD_STUBLIB}

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

pre-build:
	cd ${WRKSRC} && ${RM} -fr src/glu src/glut progs

.include "../../mk/bsd.pkg.mk"
