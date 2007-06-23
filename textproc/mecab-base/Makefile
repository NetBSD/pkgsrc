# $NetBSD: Makefile,v 1.3 2007/06/23 04:31:55 obache Exp $
#

.include "../../textproc/mecab/Makefile.common"

DISTNAME=		mecab-${MECAB_VERSION}
PKGNAME=		mecab-base-${MECAB_VERSION}

COMMENT=		Yet Another Part-of-Speech and Morphological Analyzer

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
OWN_DIRS=		${PREFIX:Q}/lib/mecab/dic

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
USE_TOOLS+=		gmake
.endif

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

TEST_TARGET=		check

EGDIR=			${PREFIX}/share/examples/mecab
CONF_FILES=		${EGDIR:Q}/mecabrc ${PKG_SYSCONFDIR:Q}/mecabrc

SUBST_CLASSES+=		confdir
SUBST_STAGE.confdir=	pre-configure
SUBST_FILES.confdir=	Makefile.in
SUBST_SED.confdir=	-e "s,\$$(sysconfdir),${EGDIR},"

SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure
SUBST_SED.pthread=	-e 's|-lpthread||g'

PTHREAD_AUTO_VARS=	yes

# XXX: avoid compiler error with -O2.
.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc*)
BUILDLINK_TRANSFORM+=	rename:-O2:-O3
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
