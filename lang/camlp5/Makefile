# $NetBSD: Makefile,v 1.8 2008/11/14 19:28:39 epg Exp $
#

DISTNAME=	camlp5-5.09
CATEGORIES=	lang
MASTER_SITES=	http://pauillac.inria.fr/~ddr/camlp5/distrib/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://pauillac.inria.fr/~ddr/camlp5/
COMMENT=	Camlp5 is a preprocessor-pretty-printer of ocaml

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c # needed for optimised compiler
MAKE_JOBS_SAFE=	no

CONFIGURE_ARGS+=	--bindir ${PREFIX}/bin
CONFIGURE_ARGS+=	--mandir ${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--libdir ${PREFIX}/lib/ocaml

REPLACE_SH=	tools/*.sh meta/*.sh ocaml_src/tools/*.sh compile/*.sh

.include "../../lang/ocaml/lib.mk"
.if defined(OCAML_OPT) && !empty(OCAML_OPT:M[yY][eE][sS])
BUILD_TARGET=		world.opt
.else
BUILD_TARGET=		world
SUBST_CLASSES+=		camlp5-opt
SUBST_STAGE.camlp5-opt=	post-configure
SUBST_FILES.camlp5-opt=	config/Makefile.cnf
SUBST_SED.camlp5-opt+=	-e 's/^OPT=.*/OPT=/'
.endif

PLIST_SRC+=	${PKGDIR}/PLIST

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
