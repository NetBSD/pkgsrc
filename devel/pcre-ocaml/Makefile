# $NetBSD: Makefile,v 1.1.1.1 2006/05/20 14:22:04 rillig Exp $
#

DISTNAME=		pcre-ocaml-5.10.3
CATEGORIES=		devel
MASTER_SITES=		http://www.ocaml.info/ocaml_sources/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://www.ocaml.info/ocaml_sources/
COMMENT=		Perl compatible regular expressions for OCaml

BUILD_DEPENDS+=		ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
USE_TOOLS+=		gmake

EGDIR=			${PREFIX}/share/examples/pcre-ocaml
INSTALLATION_DIRS=	${EGDIR}

post-install:
	cd ${WRKSRC}/examples && ${PAX} -rw -pm . ${EGDIR}

.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
