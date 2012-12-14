# $NetBSD: Makefile,v 1.10 2012/12/14 14:32:32 jaapb Exp $
#

DISTNAME=	lwt-2.4.2
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.ocsigen.org/download/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://www.ocsigen.org/
COMMENT=	Cooperative threading library for OCaml
LICENSE=	gnu-lgpl-v2.1

BUILDLINK_API_DEPENDS.ocaml+=   ocaml>=3.11.0
DEPENDS=	ocaml-react-[0-9]*:../../devel/ocaml-react

USE_TOOLS+=	gmake
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--destdir "${DESTDIR}" --prefix "${PREFIX}" --enable-react --disable-text --disable-glib --disable-toplevel
USE_LANGUAGES+=	c

BUILD_TARGET=	build

INSTALLATION_DIRS=	lib/ocaml/site-lib

SUBST_CLASSES+=		libev destdir
SUBST_STAGE.libev=	post-configure
SUBST_MESSAGE.libev=	Correcting compiler flags for libev
SUBST_FILES.libev=	setup.data
SUBST_SED.libev=	-e 's%"-lev"%"-lev -L${PREFIX}/lib/ev -Wl,-R${PREFIX}/lib/ev"%'
SUBST_STAGE.destdir=    post-configure
SUBST_MESSAGE.destdir=  Changing install location to DESTDIR
SUBST_FILES.destdir=    setup.ml
SUBST_SED.destdir=      -e 's,"install" :: findlib_name,"install" :: "-destdir ${DESTDIR}${PREFIX}/lib/ocaml/site-lib" :: "-ldconf /dev/null" :: findlib_name,'

PLIST_VARS=	opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST.opt=		yes
.endif

do-configure:
	cd ${WRKSRC} && ${CONFIGURE_ENV} ocaml setup.ml -configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${MAKE_ENV} ocaml setup.ml -build

do-install:
	cd ${WRKSRC} && ocaml setup.ml -install

.include "options.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
