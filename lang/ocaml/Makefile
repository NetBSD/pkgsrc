# $NetBSD: Makefile,v 1.14 2003/04/19 00:16:58 jschauma Exp $
#

DISTNAME=	ocaml-3.06
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.inria.fr/lang/caml-light/${DISTNAME}/

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

.include "../../mk/bsd.pkg.mk"
