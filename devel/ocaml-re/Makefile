# $NetBSD: Makefile,v 1.6 2016/05/06 22:32:41 wiz Exp $

DISTNAME=	ocaml-re-1.2.2
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/ocaml/ocaml-re/archive/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://github.com/ocaml/ocaml-re/
COMMENT=	Pure OCaml regular expression library
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake
OCAML_USE_FINDLIB=	yes
CONFIGURE_ARGS+=	--prefix ${PREFIX}

WRKSRC=	${WRKDIR}/ocaml-re-${DISTNAME}

pre-configure:
	cd ${WRKSRC} && gmake setup.bin

do-configure:
	cd ${WRKSRC} && ./setup.bin -configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ./setup.bin -build

do-install:
	cd ${WRKSRC} && ./setup.bin -install

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
