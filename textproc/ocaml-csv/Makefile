# $NetBSD: Makefile,v 1.14 2017/09/08 09:51:25 jaapb Exp $

VERSION=	1.7
GITHUB_PROJECT=	ocaml-csv
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Chris00/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://csv.forge.ocamlcore.org/
COMMENT=	CSV library for OCaml
LICENSE=	gnu-lgpl-v2.1

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c

CONFIGURE_ARGS+=	--destdir "${DESTDIR}" --prefix "${PREFIX}" --bindir "${DESTDIR}${PREFIX}/bin"

OCAML_USE_OASIS=	yes
INSTALLATION_DIRS+=	bin

.include "../../mk/ocaml.mk"

post-wrapper:
	${RUN} cd ${WRKSRC} && ${MAKE} setup.ml

post-install:
.if ${OCAML_USE_OPT_COMPILER} == yes
	${INSTALL_PROGRAM} ${WRKSRC}/_build/examples/csvtool.native ${DESTDIR}${PREFIX}/bin/csvtool
.else
	${INSTALL_SCRIPT} ${WRKSRC}/_build/examples/csvtool.byte ${DESTDIR}${PREFIX}/bin/csvtool
.endif

.include "../../devel/ocaml-oasis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
