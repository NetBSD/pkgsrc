# $NetBSD: Makefile,v 1.4 2000/08/24 22:32:34 wiz Exp $
#

DISTNAME=		ocaml-3.00
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.inria.fr/lang/caml-light/

MAINTAINER=		groo@netbsd.org
HOMEPAGE=		http://caml.inria.fr/ocaml/

DEPENDS+=		tk-8.0.*:../../x11/tk80

USE_GMAKE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-prefix ${LOCALBASE} -tklibs -L${LOCALBASE}/lib -tkdefs "-I${LOCALBASE}/include/tcl8.0 -I${LOCALBASE}/include/tk8.0" -libs "-Wl,-R${X11BASE}/lib -Wl,-R${LOCALBASE}/lib"

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
