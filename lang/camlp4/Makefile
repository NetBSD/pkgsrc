# $NetBSD: Makefile,v 1.14 2017/07/30 22:32:19 wiz Exp $

GITHUB_PROJECT=	camlp4
DISTNAME=	${GITHUB_PROJECT}-4.04+1
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}
DIST_SUBDIR=	ocaml-camlp4

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/camlp4/
COMMENT=	Preprocessor and pretty printer for OCaml
LICENSE=	gnu-lgpl-v2

HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/camlp4-4.04-1
MAKE_JOBS_SAFE=	no

.include "../../mk/ocaml.mk"

BUILD_TARGET=	byte camlp4/META
.if ${OCAML_USE_OPT_COMPILER} == "yes"
BUILD_TARGET+=	native
.endif
INSTALLATION_DIRS+=	${OCAML_SITELIBDIR}/camlp4

do-install:
	cd ${WRKSRC} && BINDIR="${DESTDIR}${PREFIX}/bin" \
		LIBDIR="${DESTDIR}${PREFIX}/lib/ocaml" ${SH} build/install.sh
	${INSTALL_DATA} ${WRKSRC}/camlp4/META ${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}/camlp4

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
