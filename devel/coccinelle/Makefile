# $NetBSD: Makefile,v 1.35 2018/11/12 16:10:18 jaapb Exp $

DISTNAME=	coccinelle-1.0.0-rc17
PKGNAME=	${DISTNAME:S/-rc/rc/}
PKGREVISION=	15
CATEGORIES=	devel
MASTER_SITES=	http://coccinelle.lip6.fr/distrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://coccinelle.lip6.fr/
COMMENT=	Tool for writing and applying semantic patches
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

# the current version rejects this package's .mly file
#DEPENDS+=	menhir>=20071212:../../devel/menhir
CONFIGURE_ARGS+=	--without-menhir --disable-menhirLib

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
REPLACE_PERL=	configure
BUILD_TARGET=	all all.opt

SUBST_CLASSES+=		man
SUBST_FILES.man+=	configure
SUBST_SED.man+=		-e "s,$${prefix}/man,$${prefix}/${PKGMANDIR},g"
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing manpath.

TEST_TARGET=	test

.include "../../lang/python/tool.mk"

.include "../../mk/dlopen.buildlink3.mk"

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.11
.include "../../lang/ocaml/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
