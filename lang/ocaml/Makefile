# $NetBSD: Makefile,v 1.9 2002/01/14 18:10:29 wiz Exp $
#

DISTNAME=		ocaml-3.01
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.inria.fr/lang/caml-light/ocaml-3.01/

MAINTAINER=		groo@netbsd.org
HOMEPAGE=		http://caml.inria.fr/ocaml/
COMMENT=		the latest implementation of the Caml dialect of ML

DEPENDS+=		tk>=8.3.2:../../x11/tk

USE_GMAKE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-prefix ${LOCALBASE} -tklibs -L${LOCALBASE}/lib -tkdefs "-I${LOCALBASE}/include " -libs "-Wl,-R${X11BASE}/lib -Wl,-R${LOCALBASE}/lib"

ALL_TARGET=		world

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
