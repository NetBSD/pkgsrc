# $NetBSD: Makefile,v 1.1 2013/12/15 02:00:07 dholland Exp $

DISTNAME=	ghc-6.8.3
PKGNAME=	ghc-bootstrap-6.8.3
CATEGORIES=	lang
MASTER_SITES=	http://www.haskell.org/ghc/dist/6.8.3/
DISTFILES=	ghc-6.8.3-src.tar.bz2

OWNER=		dholland@NetBSD.org
HOMEPAGE=	http://www.haskell.org/ghc/
COMMENT=	Bootstrap kit generator for the GHC Haskell compiler

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
#USE_TOOLS+=		gmake perl:run
USE_TOOLS+=		gmake perl

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	mk/bootstrap.mk
SUBST_FILES.prefix+=	libraries/readline/configure
SUBST_FILES.prefix+=	libraries/readline/readline.cabal
SUBST_FILES.prefix+=	rts/package.conf.in
SUBST_SED.prefix=	-e 's,@PREFIX@,${PREFIX},g'

# The ghc compiler normally splits the generated C files into small
# parts before sending them to gcc, to enable the linker to eliminate
# unused parts.  This does however not play nice with the pkgsrc
# framework, and the result is that the build takes more than 5 times
# as long than when the files are not split.  See
#    http://mail-index.netbsd.org/tech-pkg/2006/07/30/0005.html
# for a description of the problem.
# Disable file splitting until pkgsrc has been improved.
#
# Also, for the bootstrap kit, at least for the time being, do a
# fast build. This should probably be tinkered with in the future
# so as to provide the smallest/fastest bootstrap kit that can
# still compile GHC.
pre-configure:
	${ECHO} "SplitObjs=NO" > ${WRKSRC}/mk/build.mk
	${ECHO} "BuildFlavour=quickest" >> ${WRKSRC}/mk/build.mk

# uses the UNDO_ constants
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
