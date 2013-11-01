# $NetBSD: Makefile,v 1.5 2013/11/01 11:30:22 jaapb Exp $

PKGNAME=	ocaml-${DISTNAME}
DISTNAME=	react-0.9.4
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://erratique.ch/software/react/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://erratique.ch/software/react
COMMENT=	OCaml module for functional reactive programming
LICENSE=	modified-bsd

USE_LANGUAGES=	c
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix "${PREFIX}" --destdir "${DESTDIR}"

SUBST_CLASSES+=   destdir
SUBST_STAGE.destdir=  post-configure
SUBST_MESSAGE.destdir=  Changing install location to DESTDIR
SUBST_FILES.destdir=  setup.ml
SUBST_SED.destdir=      -e 's,"install" :: findlib_name,"install" :: "-destdir ${DESTDIR}${PREFIX}/lib/ocaml/site-lib" :: "-ldconf /dev/null" :: findlib_name,'

DEPENDS+=       ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

PLIST_VARS+=	opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST.opt=	yes

post-build:
	cd ${WRKSRC} && ocamlbuild src/react.cmxs

post-install:
	cd ${WRKSRC} && ${INSTALL_LIB} _build/src/react.cmxs ${DESTDIR}${PREFIX}/lib/ocaml/site-lib/react
.endif

do-configure:
	cd ${WRKSRC} && ocaml setup.ml -configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ocaml setup.ml -build

pre-install:
	${MKDIR} ${DESTDIR}/${PREFIX}/lib/ocaml/site-lib

do-install:
	cd ${WRKSRC} && ocaml setup.ml -install

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
