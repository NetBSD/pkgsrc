# $NetBSD: Makefile,v 1.5 2000/04/05 20:43:17 tron Exp $

DISTNAME=	glx-19990804
PKGNAME=	Mesa-${DISTNAME:S/-/-${GLX_CHIPSET}-/}
CATEGORIES=	graphics
MASTER_SITES=	http://glx.on.openprojects.net/snap/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://glx.on.openprojects.net/

BROKEN=		update required for Mesa 3.1.

BUILD_DEPENDS+=	${PERL}:../../lang/perl5
BUILD_DEPENDS+=	${TCLSH}:../../lang/tcl80
BUILD_DEPENDS+=	${MESA_WRKSRC}/lib/libMesaGL.a:${MESA_PKGDIR}:build

CONFLICTS+=		Mesa-*
ONLY_FOR_PLATFORM=	NetBSD-*-i386

# Either "mga" (Matrox MGA 200 and 400) or "tnt" (Riva TNT and TNT 2)
GLX_CHIPSET?=	mga

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
USE_X11BASE=		yes
CONFIGURE_ARGS+=	--with-mmx-asm=no --with-3dnow-asm=no \
			--with-chipset=${GLX_CHIPSET} \
			--with-mesa=${MESA_WRKSRC}
CONFIGURE_ENV+=		TCLSH=${TCLSH}

BUILD_DEFS+=	GLX_CHIPSET
MAKE_ENV+=		PERL=${PERL}
MESA_PKGDIR=	../Mesa
MESA_VERSION=	3.0
MESA_WRKSRC=	${BUILD_ROOT}/graphics/Mesa/${WRKDIR:T}/Mesa-${MESA_VERSION}
PERL=		${LOCALBASE}/bin/perl
PLIST_SRC=	${WRKDIR}/PLIST
TCLSH=		${LOCALBASE}/bin/tclsh8.0

pre-install:
	cd ${MESA_PKGDIR} && ${MAKE} do-install

post-install:
	cd ${PREFIX}/lib; \
	for EXT in a so.${MESA_VERSION} ; do \
	  ${LN} -fs libGL.$${EXT} libMesaGL.$${EXT}; \
	  ${LN} -fs libGLU.$${EXT} libMesaGLU.$${EXT}; \
	done
	@${CP} ${MESA_PKGDIR}/pkg/PLIST ${PLIST_SRC}
	@${ECHO} "lib/modules/glx.so" >> ${PLIST_SRC}

pre-clean:
	@cd ${MESA_PKGDIR} && ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
