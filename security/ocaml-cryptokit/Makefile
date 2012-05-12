# $NetBSD: Makefile,v 1.1.1.1 2012/05/12 17:53:40 wiz Exp $
#

DISTNAME=	cryptokit-1.5
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/639/

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://forge.ocamlcore.org/projects/cryptokit/
COMMENT=	Cryptographic primitives library for Objective Caml
LICENSE=	gnu-lgpl-v2 # with static compilation exception

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--destdir "${DESTDIR}" --prefix "${PREFIX}"

USE_TOOLS+=	gmake
PLIST_SRC=	PLIST

SUBST_CLASSES+=		destdir
SUBST_STAGE.destdir=	post-configure
SUBST_MESSAGE.destdir=	Changing install location to DESTDIR
SUBST_FILES.destdir=	setup.ml
SUBST_SED.destdir=      -e 's,"install" :: findlib_name,"install" :: "-destdir ${DESTDIR}${PREFIX}/lib/ocaml/site-lib" :: "-ldconf /dev/null" :: findlib_name,'

BUILD_TARGET=	build

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST_SRC+=	PLIST.opt
post-build:
	cd ${WRKSRC} && ocamlbuild src/cryptokit.cmxs

post-install:
	cd ${WRKSRC} && ${INSTALL_LIB} _build/src/cryptokit.cmxs ${DESTDIR}/${PREFIX}/lib/ocaml/site-lib/cryptokit
.endif

pre-install:
	${RM} -rf ${DESTDIR}/${PREFIX}/lib/ocaml/site-lib/cryptokit
	${MKDIR} ${DESTDIR}/${PREFIX}/lib/ocaml/site-lib

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
