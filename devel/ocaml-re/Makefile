# $NetBSD: Makefile,v 1.4 2016/02/06 12:10:33 jaapb Exp $

DISTNAME=	ocaml-re-1.2.2
PKGREVISION=	2
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

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
