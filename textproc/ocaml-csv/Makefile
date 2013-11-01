# $NetBSD: Makefile,v 1.2 2013/11/01 11:30:23 jaapb Exp $

PKGNAME= ocaml-${DISTNAME}
DISTNAME=	csv-1.3.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1172/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://csv.forge.ocamlcore.org/
COMMENT=	CSV library for OCaml
LICENSE=	gnu-lgpl-v2.1

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c

CONFIGURE_ARGS+=	--destdir "${DESTDIR}" --prefix "${PREFIX}"

SUBST_CLASSES+=	destdir
SUBST_STAGE.destdir=    post-configure
SUBST_MESSAGE.destdir=  Changing install location to DESTDIR
SUBST_FILES.destdir=    setup.ml
SUBST_SED.destdir=      -e 's,"install" :: findlib_name,"install" :: "-destdir ${DESTDIR}${PREFIX}/lib/ocaml/site-lib" :: "-ldconf /dev/null" :: findlib_name,'

PLIST_VARS=     opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST.opt=	yes
.endif

do-configure:
	cd ${WRKSRC} && ${CONFIGURE_ENV} ocaml setup.ml -configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${MAKE_ENV} ocaml setup.ml -build

do-install:
	cd ${WRKSRC} && ocaml setup.ml -install

.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
