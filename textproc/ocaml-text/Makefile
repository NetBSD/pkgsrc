# $NetBSD: Makefile,v 1.1.1.1 2012/06/04 14:28:15 wiz Exp $
#

DISTNAME=	ocaml-text-0.5
CATEGORIES=	textproc
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/641/

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://ocaml-text.forge.ocamlcore.org/
COMMENT=	OCaml Unicode library
LICENSE=	modified-bsd

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+= 	--prefix ${PREFIX} --destdir ${DESTDIR}
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=       ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

SUBST_CLASSES+=		destdir
SUBST_STAGE.destdir=	post-configure
SUBST_MESSAGE.destdir=	Changing install location to DESTDIR
SUBST_FILES.destdir=	setup.ml
SUBST_SED.destdir=	-e 's,"install" :: findlib_name,"install" :: "-destdir ${DESTDIR}${PREFIX}/lib/ocaml/site-lib" :: "-ldconf /dev/null" :: findlib_name,'

PLIST_VARS=	opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST.opt=	yes
.endif

do-configure:
	cd ${WRKSRC} && ocaml setup.ml -configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ocaml setup.ml -build

pre-install:
	${RM} -rf ${DESTDIR}/${PREFIX}/lib/ocaml/site-lib/text
	${MKDIR} ${DESTDIR}/${PREFIX}/lib/ocaml/site-lib

do-install:
	cd ${WRKSRC} && ocaml setup.ml -install

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
