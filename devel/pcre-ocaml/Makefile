# $NetBSD: Makefile,v 1.2 2006/08/11 15:03:08 wiz Exp $
#

DISTNAME=		pcre-ocaml-5.10.3
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://www.ocaml.info/ocaml_sources/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://www.ocaml.info/ocaml_sources/
COMMENT=		Perl compatible regular expressions for OCaml

DEPENDS+=		ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
USE_TOOLS+=		gmake

EGDIR=			${PREFIX}/share/examples/pcre-ocaml
INSTALLATION_DIRS=	${EGDIR}

post-install:
	cd ${WRKSRC}/examples && ${PAX} -rw -pm . ${EGDIR}

.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
