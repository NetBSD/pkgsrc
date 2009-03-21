# $NetBSD: Makefile,v 1.1.1.1 2009/03/21 23:50:53 wiz Exp $
#

DISTNAME=	coccinelle-0.1.6
CATEGORIES=	devel
MASTER_SITES=	http://www.emn.fr/x-info/coccinelle/distrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.emn.fr/x-info/coccinelle/
COMMENT=	Tool for writing and applying semantic patches

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	yes
USE_TOOLS=	gmake perl
REPLACE_PERL=	configure

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIG_SHELL=	${PERL5}

SUBST_CLASSES+=		python
SUBST_FILES.python+=	pycaml/Makefile
SUBST_SED.python+=	-e "s, python , ${PYTHONBIN} ,g"
SUBST_STAGE.python=	post-configure
SUBST_MESSAGE.python=	Fixing python executable name.

TEST_TARGET=	test

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Linux"
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif

.include "../../lang/ocaml/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
