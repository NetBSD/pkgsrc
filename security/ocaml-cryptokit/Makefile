# $NetBSD: Makefile,v 1.5 2013/11/01 11:30:22 jaapb Exp $
#

DISTNAME=	cryptokit-1.6
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/891/

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://forge.ocamlcore.org/projects/cryptokit/
COMMENT=	Cryptographic primitives library for Objective Caml
LICENSE=	gnu-lgpl-v2 # with static compilation exception

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

PLIST_VARS+=	opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST.opt=	yes
.endif

pre-install:
	${MKDIR} ${DESTDIR}/${PREFIX}/lib/ocaml/site-lib

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
