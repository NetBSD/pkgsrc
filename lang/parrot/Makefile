# $NetBSD: Makefile,v 1.8 2006/01/03 19:25:06 wiz Exp $
#

DISTNAME=		parrot-0.4.0
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/L/LT/LTOETSCH/}

MAINTAINER=		debolaz@gmail.com
HOMEPAGE=		http://www.parrotcode.org/
COMMENT=		Virtual machine made to run Perl 6 and other languages

USE_TOOLS+=		gmake perl

BUILD_TARGET=		world_shared

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--prefix=${PREFIX}/parrot \
			--icu-config=${PREFIX}/bin/icu-config \
			--verbose

# If you have another architecture, please test if it can compile
# with jit support and report status to the maintainer.

.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--jitcapable \
			--execcapable
.endif

do-configure:
	cd ${WRKSRC} && ${PERL5} Configure.pl ${CONFIGURE_ARGS}

post-configure:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.orig
	${SED}	-e '/^BIN_DIR/s|$$(EXEC_PREFIX)|${PREFIX}|' \
		-e '/^INCLUDE_DIR/s|$$(EXEC_PREFIX)/include|${PREFIX}|' \
		< ${WRKSRC}/Makefile.orig \
		> ${WRKSRC}/Makefile

post-install:
	${INSTALL_LIB} ${WRKSRC}/blib/lib/libparrot.* ${PREFIX}/lib

.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
