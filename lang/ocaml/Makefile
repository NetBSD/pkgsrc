# $NetBSD: Makefile,v 1.21 2003/11/10 23:12:47 dmcmahill Exp $
#

DISTNAME=	ocaml-3.06
PKGREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/cristal/ocaml/${DISTNAME}/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://caml.inria.fr/ocaml/
COMMENT=	The latest implementation of the Caml dialect of ML

DEPENDS+=	tk>=8.3.2:../../x11/tk

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	-prefix ${LOCALBASE}
CONFIGURE_ARGS+=	-tklibs -L${LOCALBASE}/lib
CONFIGURE_ARGS+=	-tkdefs "-I${LOCALBASE}/include "
CONFIGURE_ARGS+=	-libs "${OCAML_LDFLAGS}"
OCAML_LDFLAGS=		-Wl,${RPATH_FLAG}${X11BASE}/lib			\
			-Wl,${RPATH_FLAG}${LOCALBASE}/lib
FIX_RPATH+=		OCAML_LDFLAGS

ALL_TARGET=	world

post-extract:
	${CP} ${WRKSRC}/asmrun/power-elf.S ${WRKSRC}/asmrun/power-bsd.S

post-build:
	if ${TEST} ${MACHINE_ARCH} = 'i386' -o ${MACHINE_ARCH} = 'powerpc' \
		-o ${MACHINE_ARCH} = 'sparc' ; then \
		cd ${WRKSRC}; \
		${GMAKE} opt; \
		${GMAKE} opt.opt; \
	fi

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc")
PLIST_SRC=	${PKGDIR}/PLIST.opt ${PKGDIR}/PLIST
.else
PLIST_SRC=	${PKGDIR}/PLIST
.endif

PTHREAD_OPTS+=	native
.include "../../mk/pthread.buildlink2.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} != "none")
CONFIGURE_ARGS+=	-with-pthread
PLIST_SRC+=		${PKGDIR}/PLIST.threads
PLIST_SUBST+=		NATIVE_THREADS="@comment "
.else
PLIST_SUBST+=		NATIVE_THREADS=
.endif

PLIST_SRC+=		${PKGDIR}/PLIST.common_end

.include "../../mk/bsd.pkg.mk"
