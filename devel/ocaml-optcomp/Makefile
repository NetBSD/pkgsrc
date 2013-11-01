# $NetBSD: Makefile,v 1.1 2013/11/01 11:40:00 jaapb Exp $

DISTNAME=	optcomp-1.4
CATEGORIES=	devel
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1011/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://optcomp.forge.ocamlcore.org/
COMMENT=	OCaml syntax extension for optional compilation
LICENSE=	modified-bsd

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--destdir "${DESTDIR}" --prefix "${PREFIX}"
USE_LANGUAGES=	c

SUBST_CLASSES+=	destdir
SUBST_STAGE.destdir=    post-configure
SUBST_MESSAGE.destdir=  Changing install location to DESTDIR
SUBST_FILES.destdir=    setup.ml
SUBST_SED.destdir=      -e 's,"install" :: findlib_name,"install" :: "-destdir ${DESTDIR}${PREFIX}/lib/ocaml/site-lib" :: "-ldconf /dev/null" :: findlib_name,'

INSTALLATION_DIRS=	lib/ocaml/site-lib/optcomp

PLIST_VARS=     opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST.opt=              yes
.endif

do-configure:
	cd ${WRKSRC} && ocaml setup.ml -configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ocaml setup.ml -build

do-install:
	cd ${WRKSRC} && ocaml setup.ml -install

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
