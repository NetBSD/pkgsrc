# $NetBSD: Makefile,v 1.10 2016/07/02 10:11:09 jaapb Exp $

VERSION=	1.5
GITHUB_PROJECT=	ocaml-csv
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Chris00/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://csv.forge.ocamlcore.org/
COMMENT=	CSV library for OCaml
LICENSE=	gnu-lgpl-v2.1

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c

CONFIGURE_ARGS+=	--destdir "${DESTDIR}" --prefix "${PREFIX}"

OCAML_USE_OASIS=	yes

#SUBST_CLASSES+=	destdir
#SUBST_STAGE.destdir=    post-configure
#SUBST_MESSAGE.destdir=  Changing install location to DESTDIR
#SUBST_FILES.destdir=    setup.ml
#SUBST_SED.destdir=      -e 's,"install" :: findlib_name,"install" :: "-destdir ${DESTDIR}${PREFIX}/lib/ocaml/site-lib" :: "-ldconf /dev/null" :: findlib_name,'

pre-configure:
	cd ${WRKSRC} && ${MAKE} setup.ml

.include "../../mk/bsd.prefs.mk"

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-oasis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
