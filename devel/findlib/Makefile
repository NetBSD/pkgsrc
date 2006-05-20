# $NetBSD: Makefile,v 1.1.1.1 2006/05/20 10:18:03 rillig Exp $
#

DISTNAME=		findlib-1.1.2pl1
CATEGORIES=		devel
MASTER_SITES=		http://www.ocaml-programming.de/packages/

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://www.ocaml-programming.de/packages/
COMMENT=		Library finder for OCaml

USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-bindir ${PREFIX}/bin
CONFIGURE_ARGS+=	-mandir ${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	-config ${PKG_SYSCONFDIR}/ocamlfind.conf

EGDIR=			${PREFIX}/share/examples/ocaml-findlib
INSTALL_MAKE_FLAGS+=	OCAMLFIND_CONF=${EGDIR}/ocamlfind.conf

CONF_FILES=		${EGDIR}/ocamlfind.conf ${PKG_SYSCONFDIR}/ocamlfind.conf

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
