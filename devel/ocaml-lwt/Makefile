# $NetBSD: Makefile,v 1.6 2012/05/30 13:40:59 wiz Exp $
#

DISTNAME=	lwt-2.3.2
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.ocsigen.org/download/

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://www.ocsigen.org/
COMMENT=	Cooperative threading library for OCaml
LICENSE=	gnu-lgpl-v2.1

BUILDLINK_API_DEPENDS.ocaml+=   ocaml>=3.11.0
BUILD_DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
DEPENDS+=	ocaml-react-[0-9]*:../../devel/ocaml-react

USE_TOOLS+=	gmake
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--destdir "${DESTDIR}" --prefix "${PREFIX}" --enable-react --disable-text --disable-glib --disable-toplevel
USE_LANGUAGES+=	c

BUILD_TARGET=	build

PKG_DESTDIR_SUPPORT=	user-destdir

AUTO_MKDIRS=		yes

SUBST_CLASSES+=		destdir
SUBST_STAGE.destdir=	post-configure
SUBST_MESSAGE.destdir=	Changing install location to DESTDIR
SUBST_FILES.destdir=	setup.ml
SUBST_SED.destdir=	-e 's,"install" :: findlib_name,"install" :: "-destdir ${DESTDIR}${PREFIX}/lib/ocaml/site-lib" :: "-ldconf /dev/null" :: findlib_name,'

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST_SUBST+=	OPT=""
.else
PLIST_SUBST+=	OPT="@comment "
.endif

do-configure:
	cd ${WRKSRC} && ${CONFIGURE_ENV} ocaml setup.ml -configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${MAKE_ENV} ocaml setup.ml -build

do-install:
	${RM} -rf ${DESTDIR}${PREFIX}/lib/ocaml/site-lib/lwt
	${MKDIR} ${DESTDIR}${PREFIX}/lib/ocaml/site-lib
	cd ${WRKSRC} && ${MAKE_ENV} ocaml setup.ml -install --destdir ${DESTDIR} --prefix ${PREFIX}

.include "options.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
