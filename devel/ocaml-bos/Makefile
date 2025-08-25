# $NetBSD: Makefile,v 1.7 2025/08/25 08:34:56 wiz Exp $

DISTNAME=	bos-0.2.1
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://erratique.ch/software/bos/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://erratique.ch/software/bos
COMMENT=	Basic OS interaction for OCaml
LICENSE=	isc

CONFIGURE_ARGS+=	--prefix "${PREFIX}" --destdir "${DESTDIR}"
INSTALLATION_DIRS+=	${OCAML_SITELIBDIR}/bos

OCAML_USE_TOPKG=	yes
OCAML_USE_OPAM=		yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../devel/ocaml-astring/buildlink3.mk"
.include "../../devel/ocaml-fmt/buildlink3.mk"
.include "../../devel/ocaml-fpath/buildlink3.mk"
.include "../../devel/ocaml-logs/buildlink3.mk"
.include "../../devel/ocaml-rresult/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
