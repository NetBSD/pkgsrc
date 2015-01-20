# $NetBSD: Makefile,v 1.21 2015/01/20 14:24:36 jaapb Exp $
#

DISTNAME=	camlp5-6.12
PKGNAME=	${DISTNAME} # to avoid being called ocaml-camlp5
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://camlp5.gforge.inria.fr/distrib/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://camlp5.gforge.inria.fr/
COMMENT=	Camlp5 is a preprocessor-pretty-printer of ocaml
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
