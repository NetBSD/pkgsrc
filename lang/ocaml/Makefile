# $NetBSD: Makefile,v 1.1.1.1 2000/05/05 04:56:56 groo Exp $
#

DISTNAME=		ocaml-3.00
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.inria.fr/lang/caml-light/

MAINTAINER=		groo@netbsd.org
HOMEPAGE=		http://caml.inria.fr/ocaml/

DEPENDS+=		tk-8.0.*:../../x11/tk80

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-prefix ${LOCALBASE} -tklibs -L${LOCALBASE}/lib -tkdefs "-I${LOCALBASE}/include/tcl8.0 -I${LOCALBASE}/include/tk8.0" -libs "-Wl,-R${X11BASE}/lib -Wl,-R${LOCALBASE}/lib"

ALL_TARGET=		world

.include "../../mk/bsd.pkg.mk"
