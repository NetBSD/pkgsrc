# $NetBSD: Makefile,v 1.1 2026/09/06 09:44:10 bsiegert Exp $

DISTNAME=	chicken-6.0.0
CATEGORIES=	lang
MASTER_SITES=	http://code.call-cc.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.call-cc.org/
COMMENT=	Scheme to C compiler, handling R5RS and R7RS (small)
LICENSE=	modified-bsd

MAKE_JOBS_SAFE=	no

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
UNLIMIT_RESOURCES=	datasize

.include "../../mk/bsd.prefs.mk"

# PLATFORM detection:
.if ${OPSYS:M*BSD} || ${OPSYS} == "DragonFly"
PLATFORM=		bsd
.elif ${OPSYS} == "Linux"
PLATFORM=		linux
.elif ${OPSYS} == "Darwin"
PLATFORM=		macosx
.elif ${OPSYS} == "SunOS"
PLATFORM=		solaris
.elif ${OPSYS} == "Haiku"
PLATFORM=		haiku
.else
# possible choices left: aix android cross-linux-mingw cygwin hurd mingw
#                        mingw-msys
PKG_SKIP_REASON+=	"${OPSYS} is not supported"
.endif

MAKE_FILE=	GNUmakefile
MAKE_ENV+=	C_COMPILER=${CC:Q}
MAKE_ENV+=	HOST=	# fix ${HOST} prepending ${CC}
# Need to have these in MAKE_FLAGS, MAKE_ENV is not enough due to the
# way the build system overrides them.
MAKE_FLAGS+=	PLATFORM=${PLATFORM:Q} PREFIX=${PREFIX} DESTDIR=${DESTDIR}

BUILD_DEFS+=		CHICKEN_BINARY_VERSION
CHICKEN_BINARY_VERSION=	12

OWN_DIRS+=	${PREFIX}/lib/chicken
OWN_DIRS+=	${PREFIX}/lib/chicken/${CHICKEN_BINARY_VERSION}

BUILD_TARGET=		all

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	INFODIR=${PREFIX}/${PKGINFODIR}
MAKE_FLAGS+=	DOCDIR=${PREFIX}/share/doc/${PKGNAME_NOREV}
MAKE_FLAGS+=	INSTALL_PROGRAM=${INSTALL:Q}
MAKE_FLAGS+=	LINKER_OPTIONS=${LDFLAGS:Q}
MAKE_FLAGS+=	C_COMPILER_OPTIMIZATION_OPTIONS=${CFLAGS:Q}

TEST_TARGET=	check

PLIST_VARS+=		uses_soname
.if ${PLATFORM} != macosx
PLIST.uses_soname=	yes
.endif

PLIST_SUBST+=		CHICKEN_BINARY_VERSION=${CHICKEN_BINARY_VERSION:Q}
PRINT_PLIST_AWK+=	{ sub("/${CHICKEN_BINARY_VERSION}/", "/$${CHICKEN_BINARY_VERSION}/") }
PRINT_PLIST_AWK+=	{ sub(".so.${CHICKEN_BINARY_VERSION}$$", ".so.$${CHICKEN_BINARY_VERSION}") }

.include "../../mk/bsd.pkg.mk"
