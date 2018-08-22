# $NetBSD: Makefile,v 1.58 2018/08/22 09:45:20 wiz Exp $

DISTNAME=	ghc-6.8.3
PKGREVISION=	8
CATEGORIES=	lang
MASTER_SITES=	http://www.haskell.org/ghc/dist/6.8.3/
DISTFILES=	ghc-6.8.3-src.tar.bz2 \
		ghc-6.8.3-src-extralibs.tar.bz2 \
		ghc-6.4.2-src.tar.bz2 \
		ghc-6.4.2-i386-unknown-netbsd-hc.tar.gz

OWNER=		kristerw@NetBSD.org
HOMEPAGE=	http://www.haskell.org/ghc/
COMMENT=	Compiler for the functional language Haskell

SITES.ghc-6.4.2-src.tar.bz2=http://www.haskell.org/ghc/dist/6.4.2/
SITES.ghc-6.4.2-i386-unknown-netbsd-hc.tar.gz=${MASTER_SITE_LOCAL}

# There is only an i386 bootstrap kit available.
ONLY_FOR_PLATFORM= Darwin-*-i386 FreeBSD-*-i386 NetBSD-*-i386 OpenBSD-*-i386 SunOS-*-i386

CHECK_PORTABILITY_SKIP=	distrib/prep-bin-dist-mingw

# += in a shell script, but in embedded AWK code, so it's ok.
CHECK_PORTABILITY_SKIP+=	libraries/base/cbits/ubconfc

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ghc=${WRKDIR}/ghc-6.4.2/ghc/compiler/ghc-inplace
CONFIGURE_ENV+=		PerlCmd=${PERL5:Q}
USE_TOOLS+=		gmake perl:run

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	../ghc-6.4.2/mk/bootstrap.mk
SUBST_FILES.prefix+=	../ghc-6.4.2/ghc/rts/package.conf.in
SUBST_FILES.prefix+=	../ghc-6.4.2/libraries/readline/package.conf.in
SUBST_FILES.prefix+=	libraries/readline/configure
SUBST_FILES.prefix+=	libraries/readline/readline.cabal
SUBST_FILES.prefix+=	rts/package.conf.in
SUBST_SED.prefix=	-e 's,@PREFIX@,${PREFIX},g'

pre-configure:
	cd ${WRKDIR}/ghc-6.4.2 && \
		./distrib/hc-build --enable-hc-boot-unregisterised

# The ghc compiler does normally split the generated C files into small
# parts before sending them to gcc, to enable the linker to eliminate
# unused parts.  This does however not play nice with the pkgsrc
# framework, and the result is that the build takes more than 5 times
# as long than when the files are not split.  See
#    http://mail-index.netbsd.org/tech-pkg/2006/07/30/0005.html
# for a description of the problem.
# Disable file splitting until pkgsrc has been improved.
pre-build:
	${ECHO} "SplitObjs=NO" > ${WRKSRC}/mk/build.mk

# uses the UNDO_ constants
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
