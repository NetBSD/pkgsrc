# $NetBSD: Makefile,v 1.1.1.1 2012/02/27 11:24:13 obache Exp $
#

DISTNAME=		mecab-0.98
PKGNAME=		mecab-base-0.98
CATEGORIES=		japanese textproc
MASTER_SITES=		http://mecab.googlecode.com/files/

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://mecab.sourceforge.net/
COMMENT=		Yet Another Part-of-Speech and Morphological Analyzer
LICENSE=		gnu-gpl-v2 OR gnu-lgpl-v2.1 OR modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
OWN_DIRS=		${PREFIX:Q}/lib/mecab/dic

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

.if ${OPSYS} == "SunOS"
USE_TOOLS+=		gmake
.  if !empty(CC_VERSION:Mgcc-4.[6-9].*)
CFLAGS.SunOS+=		-D_XOPEN_SOURCE=600 -std=c99
.  endif
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

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
