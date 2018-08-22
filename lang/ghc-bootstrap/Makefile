# $NetBSD: Makefile,v 1.6 2018/08/22 09:45:20 wiz Exp $

DISTNAME=	ghc-6.8.3
PKGNAME=	ghc-bootstrap-6.8.3
PKGREVISION=	5
CATEGORIES=	lang
MASTER_SITES=	http://www.haskell.org/ghc/dist/6.8.3/
DISTFILES=	ghc-6.8.3-src.tar.bz2

OWNER=		dholland@NetBSD.org
HOMEPAGE=	http://www.haskell.org/ghc/
COMMENT=	Bootstrap kit generator for the GHC Haskell compiler

#
# build defs
#

CONFLICTS+=	ghc-[0-9]*
# Disable this (at least for now) so bootstrap kits get built by autobuilds.
#NOT_FOR_BULK_PLATFORM=	*-*-*	# Package is useful only for maintainers.

CHECK_PORTABILITY_SKIP=	distrib/prep-bin-dist-mingw

# += in a shell script, but in embedded AWK code, so it's ok.
CHECK_PORTABILITY_SKIP+=	libraries/base/cbits/ubconfc

GNU_CONFIGURE=		yes
#CONFIGURE_ARGS+=	--with-ghc=${WRKDIR}/ghc-6.4.2/ghc/compiler/ghc-inplace
CONFIGURE_ARGS+=	--with-ghc=${BUILDLINK_PREFIX.ghc}/bin/ghc
CONFIGURE_ENV+=		PerlCmd=${PERL5:Q}
#USE_TOOLS+=		gmake pkg-config perl:run
USE_TOOLS+=		gmake pkg-config perl

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	mk/bootstrap.mk
SUBST_FILES.prefix+=	libraries/readline/configure
SUBST_FILES.prefix+=	libraries/readline/readline.cabal
SUBST_FILES.prefix+=	rts/package.conf.in
SUBST_SED.prefix=	-e 's,@PREFIX@,${PREFIX},g'

#
# Build system settings.
#
# 1. The ghc compiler normally splits the generated C files into small
# parts before sending them to gcc, to enable the linker to eliminate
# unused parts.  This does however not play nice with the pkgsrc
# framework, and the result is that the build takes more than 5 times
# as long than when the files are not split.  See
#    http://mail-index.netbsd.org/tech-pkg/2006/07/30/0005.html
# for a description of the problem.
# Disable file splitting until pkgsrc has been improved.
#
# 2. For the bootstrap kit, set GhcLibWays=v; this excludes p
# (profiling libs) which take time to build and are quite useless for
# bootstrapping.
#
# 3. Later GHC versions let you set INTEGER_LIBRARY=integer-simple to
# avoid depending on gmp. This is not available in 6.8.3; instead we
# have GHC build with the rather old copy of gmp it comes with. It is
# important for the bootstrap kit to not depend on the pkgsrc shared
# gmp library, since then if its major version changes you'd be stuck.
#
pre-configure:
	${ECHO} "SplitObjs=NO" > ${WRKSRC}/mk/build.mk
	${ECHO} "GhcLibWays=v" >> ${WRKSRC}/mk/build.mk
#	${ECHO} "INTEGER_LIBRARY=integer-simple" >> ${WRKSRC}/mk/build.mk

#
# Configure script hacks.
#
# Disable readline, and disable external gmp in favor of the in-tree
# copy shipped with ghc 6.8.3. The bootstrap kit should not depend on
# shared libs from pkgsrc, as if they get their major versions bumped
# you get stuck.
#
CONFIGURE_ENV+=	ac_cv_header_readline_readline_h=no \
		ac_cv_header_readline_history_h=no \
		fp_cv_ghc_has_readline=no \
		ac_cv_lib_gmp___gmpz_fdiv_qr=no

#.include "../../devel/gmp/buildlink3.mk"

#
# As an additional measure, delete the readline and gmp .so files from
# the buildlink directory.
#
post-wrapper:
	rm -f ${WRKDIR}/.buildlink/lib/libreadline.so*
	rm -f ${WRKDIR}/.buildlink/lib/libgmp.so*
	rm -f ${WRKDIR}/.buildlink/lib/libgmpxx.so*

#
# By request of Joerg link libgcc statically so the bootstrap kit
# works on a clang-only system.
#
.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mgcc)
LDFLAGS+=	-static-libgcc
.endif

# We need to use lang/ghc to compile, and for now at least that requires
# buildlinking the compiler.
.include "../../lang/ghc/buildlink3.mk"

# Threads are required.
.include "../../mk/pthread.buildlink3.mk"

#
# make it go
#

.include "../../mk/bsd.pkg.mk"
