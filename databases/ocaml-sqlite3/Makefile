# $NetBSD: Makefile,v 1.2 2012/09/16 11:34:45 jaapb Exp $
#

PKGNAME=	ocaml-sqlite3-${VERSION}
DISTNAME=	sqlite3-ocaml-${VERSION}
VERSION=	2.0.2
CATEGORIES=	databases
MASTER_SITES=	https://bitbucket.org/mmottl/sqlite3-ocaml/downloads/
FETCH_USING=	curl

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://bitbucket.org/mmottl/sqlite3-ocaml/
COMMENT=	Sqlite bindings for OCaml
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--destdir "${DESTDIR}" --prefix "${PREFIX}"
USE_TOOLS+=	gmake
USE_LANGUAGES=	c

SUBST_CLASSES+=	destdir
SUBST_STAGE.destdir=	post-configure
SUBST_MESSAGE.destdir=	Changing install location to DESTDIR
SUBST_FILES.destdir=	setup.ml
SUBST_SED.destdir=	-e 's,"install" :: findlib_name,"install" :: "-destdir ${DESTDIR}${PREFIX}/lib/ocaml/site-lib" :: "-ldconf /var/null" :: findlib_name,'

PLIST_VARS=	opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64") || \
    (${MACHINE_ARCH} == "arm")
PLIST.opt=	yes
.endif

do-configure:
	cd ${WRKSRC} && ${CONFIGURE_ENV} ocaml setup.ml -configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${MAKE_ENV} ocaml setup.ml -build

do-install:
	cd ${WRKSRC} && ${MAKE_ENV} ocaml setup.ml -install

.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
