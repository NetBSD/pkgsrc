# $NetBSD: Makefile,v 1.11 2006/02/18 22:17:12 wiz Exp $
#

DISTNAME=		parrot-0.4.1
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/L/LT/LTOETSCH/}

MAINTAINER=		debolaz@gmail.com
HOMEPAGE=		http://www.parrotcode.org/
COMMENT=		Virtual machine made to run Perl 6 and other languages

USE_TOOLS+=		perl
PTHREAD_OPTS+=		require
BUILD_TARGET=		world
TEST_TARGET=		test

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q} \
			--icu-config=${PREFIX}/bin/icu-config

# If you have another architecture, please test if it can compile
# with (working) jit support and report status to the maintainer.

.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--jitcapable \
			--execcapable
.endif

do-configure:
	cd ${WRKSRC} && ${PERL5} Configure.pl ${CONFIGURE_ARGS}

post-configure:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.orig
	${SED}	-e 's|-pthread||g' \
		-e 's|-lpthread||g' \
		-e 's|-lc_r||g' \
		-e '/^CFLAGS /s|$$|${PTHREAD_CFLAGS}|' \
		-e '/^LINKFLAGS /s|$$|${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}|' \
		-e '/^LDFLAGS /s|$$|${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}|' \
		< ${WRKSRC}/Makefile.orig \
		> ${WRKSRC}/Makefile

post-install:
	if [ -e ${PREFIX}/lib/libparrot.so.0.4.1 ]; then \
		${LN} -s libparrot.so.0.4.1 ${PREFIX}/lib/libparrot.so ; \
	fi

.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
