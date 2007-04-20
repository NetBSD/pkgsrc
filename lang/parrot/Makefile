# $NetBSD: Makefile,v 1.13 2007/04/20 14:01:00 obache Exp $
#

DISTNAME=		parrot-0.4.11
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/MD/MDIEP/}

MAINTAINER=		debolaz@gmail.com
HOMEPAGE=		http://www.parrotcode.org/
COMMENT=		Virtual machine made to run Perl 6 and other languages

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl
PTHREAD_OPTS+=		require
BUILD_TARGET=		world
TEST_TARGET=		test
INSTALL_TARGET=		reallyinstall
HAS_CONFIGURE=		yes

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.prefs.mk"

CONFIG_SHELL=		perl
CONFIGURE_SCRIPT=	Configure.pl
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q} \
			--icu-config=${PREFIX}/bin/icu-config

# If you have another architecture, please test if it can compile
# with (working) jit support and report status to the maintainer.

.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--jitcapable \
			--execcapable
.endif

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
	if [ -e ${PREFIX}/lib/libparrot.so.0.4.1 ]; then \
		${LN} -s libparrot.so.0.4.1 ${PREFIX}/lib/libparrot.so ; \
	fi

.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
