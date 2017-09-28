# $NetBSD: Makefile,v 1.12 2017/09/28 09:15:24 jaapb Exp $

VERSION=	1.7.1
GITHUB_PROJECT=	ocaml-re
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/ocaml-re/
COMMENT=	Pure OCaml regular expression library
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake
OCAML_USE_OASIS=	yes
CONFIGURE_ARGS+=	--docdir ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

post-build:
	${RUN} cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${OASIS_EXEC} -doc ${OASIS_BUILD_ARGS}

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
