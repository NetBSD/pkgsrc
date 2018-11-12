# $NetBSD: Makefile,v 1.34 2018/11/12 16:10:51 jaapb Exp $
#

GITHUB_PROJECT=	camlp5
DISTNAME=	${GITHUB_PROJECT}-7.07
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=camlp5/}
GITHUB_TAG=	rel707

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	https://camlp5.github.io/
COMMENT=	Preprocessor-pretty-printer for ocaml
LICENSE=	modified-bsd

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c # needed for optimised compiler
MAKE_JOBS_SAFE=	no

CONFIGURE_ARGS+=	--bindir ${PREFIX}/bin
CONFIGURE_ARGS+=	--mandir ${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--libdir ${PREFIX}/lib/ocaml

REPLACE_SH=	tools/*.sh meta/*.sh ocaml_src/tools/*.sh compile/*.sh

INSTALLATION_DIRS+=	${OCAML_SITELIBDIR}/camlp5

.include "../../mk/bsd.prefs.mk"
.include "../../mk/ocaml.mk"

.if (${OCAML_USE_OPT_COMPILER} == "yes")
BUILD_TARGET=	world.opt
.else
BUILD_TARGET=	world
.endif

post-install:
	cd ${WRKSRC}/etc && \
	${INSTALL_DATA} META ${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/camlp5

.include "../../mk/bsd.pkg.mk"
