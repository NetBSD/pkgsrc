# $NetBSD: Makefile,v 1.44 2022/11/17 10:21:14 jaapb Exp $

GITHUB_PROJECT=	camlp5
DISTNAME=	${GITHUB_PROJECT}-8.00.03
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=camlp5/}
GITHUB_TAG=	rel${PKGVERSION_NOREV}
PKGREVISION=	1

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	https://camlp5.github.io/
COMMENT=	Preprocessor-pretty-printer for ocaml
LICENSE=	modified-bsd

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c # needed for optimised compiler
USE_TOOLS+=	perl gmake
MAKE_JOBS_SAFE=	no

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

CONFIGURE_ARGS+=	--bindir ${PREFIX}/bin
CONFIGURE_ARGS+=	--mandir ${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--libdir ${PREFIX}/lib/ocaml

REPLACE_SH=	tools/*.sh meta/*.sh ocaml_src/tools/*.sh compile/*.sh
REPLACE_PERL=	etc/mkcamlp5.pl

INSTALLATION_DIRS+=	${OCAML_SITELIBDIR}/camlp5

.include "../../mk/bsd.prefs.mk"
.include "../../lang/ocaml/ocaml.mk"

.if (${OCAML_USE_OPT_COMPILER} == "yes")
BUILD_TARGET=	world.opt
.else
BUILD_TARGET=	world
.endif

post-install:
	cd ${WRKSRC}/etc && \
	${INSTALL_DATA} META ${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/camlp5

.include "../../devel/camlp-streams/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
