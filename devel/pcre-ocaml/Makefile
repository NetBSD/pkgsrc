# $NetBSD: Makefile,v 1.41 2022/05/24 18:59:33 jaapb Exp $

VERSION=	7.5.0
DISTNAME=	pcre-${VERSION}
PKGNAME=	pcre-ocaml-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mmottl/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mmottl/pcre-ocaml
COMMENT=	Perl compatible regular expressions for OCaml
LICENSE=	gnu-lgpl-v2.1

WRKSRC=	${WRKDIR}/pcre-ocaml-${VERSION}

OCAML_USE_DUNE=		yes
OPAM_INSTALL_FILES=	pcre
USE_TOOLS=		pax

.include "../../mk/bsd.prefs.mk"
.include "../../lang/ocaml/ocaml.mk"

EGDIR=			${PREFIX}/share/examples/pcre-ocaml
INSTALLATION_DIRS+=	${EGDIR}
OCAML_FINDLIB_DIRS=	pcre

post-install:
	cd ${WRKSRC}/examples && pax -rw -pm . ${DESTDIR}${EGDIR}

.include "../../devel/ocaml-dune-configurator/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
