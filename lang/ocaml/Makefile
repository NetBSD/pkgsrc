# $NetBSD: Makefile,v 1.16 2003/05/22 23:58:21 hubertf Exp $
#

DISTNAME=	ocaml-3.06
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/cristal/ocaml/${DISTNAME}/

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://caml.inria.fr/ocaml/
COMMENT=	the latest implementation of the Caml dialect of ML

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

post-build:
	if ${TEST} ${MACHINE_ARCH} = 'i386'; then \
		cd ${WRKSRC}; \
		${GMAKE} opt; \
		${GMAKE} ocamlc.opt; \
		${GMAKE} ocamlopt.opt; \
	fi

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386")
PLIST_SRC=	${PKGDIR}/PLIST.opt ${PKGDIR}/PLIST
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
