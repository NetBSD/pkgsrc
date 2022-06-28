# $NetBSD: Makefile,v 1.12 2022/06/28 11:34:44 wiz Exp $

DISTNAME=	pari-2.3.5
PKGREVISION=	27
CATEGORIES=	math
MASTER_SITES=	http://pari.math.u-bordeaux.fr/pub/pari/unix/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pari.math.u-bordeaux.fr/
COMMENT=	Software package for computer-aided number theory (2.3 version)
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=	no

USE_LIBTOOL=		yes
USE_TOOLS+=		perl
USE_LANGUAGES+=		c c++
HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}
CONFIGURE_ENV+=		PERL5=${PERL5:Q}

CONFIGURE_SCRIPT=	${WRKSRC}/Configure
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}/man1
CONFIGURE_ARGS+=	--share-prefix=${PREFIX}/share

REPLACE_PERL+=		src/desc/PARI/822.pm

BUILD_TARGET=		all
TEST_TARGET=		test-compat bench
INSTALL_TARGET=		install

SUBST_CLASSES+=		fix-cfg
SUBST_STAGE.fix-cfg=	pre-configure
SUBST_MESSAGE.fix-cfg=	Adding CFLAGS to Configure scripts.
SUBST_FILES.fix-cfg=	config/get_*
SUBST_SED.fix-cfg=	-e 's,$$CC $$extraflag,$$CC $$CFLAGS $$extraflag,g'

.include "options.mk"

.include "../../devel/ncurses/buildlink3.mk"
# rl_save_prompt()
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
