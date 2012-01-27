# $NetBSD: Makefile,v 1.12 2012/01/27 08:37:01 obache Exp $

DISTNAME=	coccinelle-0.2.5
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://coccinelle.lip6.fr/distrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://coccinelle.lip6.fr/
COMMENT=	Tool for writing and applying semantic patches
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
DEPENDS+=	menhir>=20071212:../../devel/menhir

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake perl
REPLACE_PERL=	configure
BUILD_TARGET=	all all.opt

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIG_SHELL=	${PERL5}

PYTHON_VERSIONS_ACCEPTED=	27 26 25 24

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
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
