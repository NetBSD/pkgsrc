# $NetBSD: Makefile,v 1.4 2009/04/29 11:21:52 wiz Exp $

DISTNAME=	coccinelle-0.1.7
CATEGORIES=	devel
MASTER_SITES=	http://aryx.cs.uiuc.edu/~pad/software/project-coccinelle/#http://www.emn.fr/x-info/coccinelle/distrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.emn.fr/x-info/coccinelle/
COMMENT=	Tool for writing and applying semantic patches

BUILD_DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
DEPENDS+=	menhir-[0-9]*:../../devel/menhir

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
#MAKE_JOBS_SAFE=		no

HAS_CONFIGURE=	yes
USE_TOOLS=	gmake perl
REPLACE_PERL=	configure
BUILD_TARGET=	all all.opt

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIG_SHELL=	${PERL5}

PYTHON_VERSIONS_ACCEPTED=	25

SUBST_CLASSES+=		python
SUBST_FILES.python+=	pycaml/Makefile
SUBST_SED.python+=	-e "s, python , ${PYTHONBIN} ,g"
SUBST_STAGE.python=	post-configure
SUBST_MESSAGE.python=	Fixing python executable name.

SUBST_CLASSES+=		man
SUBST_FILES.man+=	docs/spatch.1
SUBST_SED.man+=		-e "s,/usr/local,${PREFIX},g"
SUBST_STAGE.man=	post-configure
SUBST_MESSAGE.man=	Fixing path to examples in man page.

TEST_TARGET=	test

.include "../../mk/dlopen.buildlink3.mk"

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

.include "../../lang/ocaml/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
