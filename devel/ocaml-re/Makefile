# $NetBSD: Makefile,v 1.20 2019/08/11 13:18:47 wiz Exp $

VERSION=	1.8.0
GITHUB_PROJECT=	ocaml-re
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/ocaml-re/
COMMENT=	Pure OCaml regular expression library
LICENSE=	gnu-lgpl-v2.1

INSTALLATION_DIRS+=	${OCAML_SITELIBDIR}/re/emacs ${OCAML_SITELIBDIR}/re/glob \
		       	${OCAML_SITELIBDIR}/re/pcre ${OCAML_SITELIBDIR}/re/perl \
			${OCAML_SITELIBDIR}/re/posix ${OCAML_SITELIBDIR}/re/str \
			share/doc/re
OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
