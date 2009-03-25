# $NetBSD: Makefile,v 1.15 2009/03/25 23:01:48 he Exp $
#

DISTNAME=		parrot-1.0.0
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.parrot.org/pub/parrot/releases/stable/1.0.0/

MAINTAINER=		he@NetBSD.org
HOMEPAGE=		http://www.parrotcode.org/
COMMENT=		Virtual machine made to run Perl 6 and other languages

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl
PTHREAD_OPTS+=		require
BUILD_TARGET=		world
TEST_TARGET=		test
HAS_CONFIGURE=		yes

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.prefs.mk"

CONFIG_SHELL=		perl
CONFIGURE_SCRIPT=	Configure.pl
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q} \
			--icu-config=${PREFIX}/bin/icu-config

SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	post-configure
SUBST_FILES.pthread=	Makefile
SUBST_SED.pthread=	-e 's|-pthread||g'
SUBST_SED.pthread+=	-e 's|-lpthread||g'
SUBST_SED.pthread+=	-e 's|-lc_r||g'
SUBST_SED.pthread+=	-e '/^CFLAGS /s|$$|${PTHREAD_CFLAGS:Q}|'
SUBST_SED.pthread+=	-e '/^LINKFLAGS /s|$$|${PTHREAD_LDFLAGS:Q} ${PTHREAD_LIBS:Q}|'
SUBST_SED.pthread+=	-e '/^LDFLAGS /s|$$|${PTHREAD_LDFLAGS:Q} ${PTHREAD_LIBS:Q}|'

post-install:
	if [ -e ${PREFIX}/lib/libparrot.so.1.0.0 ]; then \
		${LN} -s libparrot.so.1.0.0 ${PREFIX}/lib/libparrot.so ; \
	fi

.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
