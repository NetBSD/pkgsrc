# $NetBSD: Makefile,v 1.11 2003/04/29 11:27:39 augustss Exp $

DISTNAME=	ghc-5.04.3
CATEGORIES=	lang
MASTER_SITES=	http://www.haskell.org/ghc/dist/5.04.3/
DISTFILES=	ghc-5.04.3-src.tar.bz2 ghc-5.04.3-i386-unknown-netbsd-hc.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.haskell.org/ghc/
COMMENT=	Compiler for the functional language Haskell

DEPENDS+=	readline>=4.0:../../devel/readline
DEPENDS+=	gmp>=2.0.2:../../devel/gmp

USE_GNU_READLINE=yes
USE_PERL5=	yes
USE_GMAKE=	yes

# Note: this package contains a Haskell compiler that is itself
# written in Haskell. There are basically two ways we can solve the
# bootstrap problem:
# 1. bootstrap from pre-generated C files.
# 2. first download a binary pre-built compiler and use it to compile.
# We currently use way 1.
# The problem with 2. is that it may make the package more sensitive
# to the exact NetBSD versions involved (the version of the build
# system compared to the version used to build the pre-built binary).
# On the other hand, bootstrapping GHC from C is very fragile and it
# may be harder to update the package with method 1.
# For comparison, FreeBSD currently uses method 2.

# Note: a number of non-i386 platforms, including solaris/sparc,
# osf/alpha etc are supported natively by ghc. pkg support for those
# platforms and their NetBSD varients is left as a mid-level exercise
# for the reader
ONLY_FOR_PLATFORM= NetBSD-1.5*-i386 NetBSD-1.6*-i386

pre-configure:
	cd ${WRKSRC}; file=configure.in;				\
	${SED} -e "s|@PREFIX@|${PREFIX}|g" $${file} > $${file}.fixed;	\
	${MV} -f $${file}.fixed $${file};				\
	${AUTOCONF}

do-configure:
	: Nothing here, configure is run twice by the hc-build script.

do-build:
	(cd ${WRKSRC}; \
	 LIBS="-L${PREFIX}/lib" ./distrib/hc-build --prefix=${PREFIX})

.include "../../devel/readline/buildlink2.mk"
.include "../../devel/gmp/buildlink2.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
