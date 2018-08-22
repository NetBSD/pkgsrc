# $NetBSD: Makefile,v 1.75 2018/08/22 09:45:41 wiz Exp $

DISTNAME=	pari-2.7.6
PKGREVISION=	4
CATEGORIES=	math
MASTER_SITES=	http://pari.math.u-bordeaux.fr/pub/pari/unix/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pari.math.u-bordeaux.fr/
COMMENT=	Software package for computer-aided number theory
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=	no

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl:run
USE_LANGUAGES+=		c c++
HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}
CONFIGURE_ENV+=		PERL5=${PERL5:Q}
MAKE_ENV+=		PERL_USE_UNSAFE_INC=1

CONFIGURE_SCRIPT=	${WRKSRC}/Configure
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}/man1
CONFIGURE_ARGS+=	--share-prefix=${PREFIX}/share

REPLACE_PERL+=		src/desc/PARI/822.pm
REPLACE_PERL+=		doc/gphelp
REPLACE_PERL+=		misc/tex2mail

BUILD_TARGET=		all
TEST_TARGET=		test-compat bench
INSTALL_TARGET=		install

SUBST_CLASSES+=		fix-cfg
SUBST_STAGE.fix-cfg=	pre-configure
SUBST_MESSAGE.fix-cfg=	Adding CFLAGS to Configure scripts.
SUBST_FILES.fix-cfg=	config/get_*
SUBST_SED.fix-cfg=	-e 's,$$CC $$extraflag,$$CC $$CFLAGS $$extraflag,g'

SUBST_CLASSES+=		fix-wrap
SUBST_STAGE.fix-wrap=	post-build
SUBST_MESSAGE.fix-wrap=	Removing TOOLS_DIR references
SUBST_FILES.fix-wrap=	*/pari.cfg
SUBST_SED.fix-wrap=	-e "s,${TOOLS_DIR}/bin/,,g"

pre-install: replace-interpreter

.include "options.mk"

# rl_save_prompt()
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
