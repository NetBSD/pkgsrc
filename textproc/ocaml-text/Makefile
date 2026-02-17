# $NetBSD: Makefile,v 1.28 2026/02/17 13:39:13 wiz Exp $
#

DISTNAME=	ocaml-text-0.8
PKGREVISION=	12
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=vbmithr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vbmithr/ocaml-text
COMMENT=	OCaml Unicode library
LICENSE=	modified-bsd

HAS_CONFIGURE=		yes

#SUBST_CLASSES+=	destdir
#SUBST_STAGE.destdir=	post-configure
#SUBST_MESSAGE.destdir=	Changing install location to DESTDIR
#SUBST_FILES.destdir=	setup.ml
#SUBST_SED.destdir=	-e 's,"install" :: findlib_name,"install" :: "-destdir ${DESTDIR}${PREFIX}/lib/ocaml/site-lib" :: "-ldconf /dev/null" :: findlib_name,'

OCAML_USE_OASIS=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
