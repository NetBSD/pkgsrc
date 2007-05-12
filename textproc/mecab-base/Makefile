# $NetBSD: Makefile,v 1.1.1.1 2007/05/12 13:47:03 obache Exp $
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

SUBST_CLASSES+=		rpaths
SUBST_STAGE.rpaths=	pre-configure
SUBST_FILES.rpaths=	mecab-config.in
SUBST_SED.rpaths=	-e '/echo[ 	]*-L/s|-L\([ 	]*[^ 	]*\)|${COMPILER_RPATH_FLAG}\1 -L\1|g'

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
