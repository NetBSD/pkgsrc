# $NetBSD: Makefile,v 1.11 2017/09/08 09:51:21 jaapb Exp $

DISTNAME=	oasis-0.4.10
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1694/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://oasis.forge.ocamlcore.org/
COMMENT=	Build system for OCaml projects
LICENSE=	gnu-lgpl-v2.1

OCAML_USE_OASIS=	yes
CONFIGURE_ARGS+=	--bindir ${DESTDIR}${PREFIX}/bin --enable-libraries
INSTALLATION_DIRS+=	bin

OCAML_FINDLIB_DIRS+=	plugin-loader

.include "../../mk/ocaml.mk"

post-install:
.if ${OCAML_USE_OPT_COMPILER} == "yes"
	${INSTALL_PROGRAM} ${WRKSRC}/_build/src/cli/Main.native ${DESTDIR}${PREFIX}/bin/oasis
.else
	${INSTALL_SCRIPT} ${WRKSRC}/_build/src/cli/Main.byte ${DESTDIR}${PREFIX}/bin/oasis
.endif

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../devel/ocamlify/buildlink3.mk"
.include "../../devel/ocamlmod/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
