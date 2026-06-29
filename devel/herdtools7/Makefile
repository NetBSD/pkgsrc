# $NetBSD: Makefile,v 1.1 2026/06/29 00:53:14 dholland Exp $

DISTNAME=	herdtools7-7.58
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=herd/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/herd/herdtools7/
COMMENT=	Weak memory model litmus tester
LICENSE=	cecill-b-v1 AND modified-bsd AND isc

USE_TOOLS+=	pax
TOOL_DEPENDS+=	menhir-[0-9]*:../../devel/menhir

# This package has a (gmake) makefile; however, it runs dune, and to
# get dune to behave itself and to get a useful install behavior we
# need to use the infrastructure. So do that instead of building with
# the makefile. There are two additional things the makefile does; one
# is generate Version.ml and the other is to install some extra files;
# there are explicit rules for these steps below.
OCAML_USE_DUNE=	yes

pre-build:
	${RUN} cd ${WRKSRC} && sh ./version-gen.sh ${PREFIX}

BITSDIR=	${PREFIX}/share/herdtools7
post-install:
	cd ${WRKSRC}/herd/libdir && pax -rw . ${DESTDIR}${BITSDIR}/herd
	cd ${WRKSRC}/litmus/libdir && pax -rw . ${DESTDIR}${BITSDIR}/litmus
	cd ${WRKSRC}/jingle/libdir && pax -rw . ${DESTDIR}${BITSDIR}/jingle

# uses unsigned conversions
BUILDLINK_API_DEPENDS.ocaml-zarith+=	ocaml-zarith>=1.13
.include "../../math/ocaml-zarith/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"

.include "../../mk/bsd.pkg.mk"
