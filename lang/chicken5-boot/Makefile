# $NetBSD: Makefile,v 1.1 2023/04/26 18:09:54 nikita Exp $

DISTNAME=	chicken-5.3.0
PKGNAME=	${DISTNAME:S/chicken/chicken5-boot/}
CATEGORIES=	lang
MASTER_SITES=	http://code.call-cc.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.call-cc.org/
COMMENT=	Scheme to C compiler, handling R5RS (bootstrap)
LICENSE=	modified-bsd

MAKE_JOBS_SAFE=	no

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
UNLIMIT_RESOURCES=	datasize

BUILD_DEFS+=		CHICKEN_BINARY_VERSION
CHICKEN_BINARY_VERSION=	11

BUILD_TARGET=		boot-chicken
WRKSRC=			${WRKDIR}/chicken-${PKGVERSION_NOREV}
INSTALLATION_DIRS+=	libexec

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
#PLATFORM+=		${OPSYS} == "Interix"
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
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	INFODIR=${PREFIX}/${PKGINFODIR}
MAKE_FLAGS+=	DOCDIR=${PREFIX}/share/doc/${PKGNAME_NOREV}
MAKE_FLAGS+=	INSTALL_PROGRAM=${INSTALL:Q}

TEST_TARGET=	check

PLIST_SUBST+=		CHICKEN_BINARY_VERSION=${CHICKEN_BINARY_VERSION:Q}
PRINT_PLIST_AWK+=	{ sub("/${CHICKEN_BINARY_VERSION}/", "/$${CHICKEN_BINARY_VERSION}/") }
PRINT_PLIST_AWK+=	{ sub(".so.${CHICKEN_BINARY_VERSION}$$", ".so.$${CHICKEN_BINARY_VERSION}") }

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chicken-boot ${DESTDIR}${PREFIX}/libexec/chicken-bootstrap

.include "../../mk/bsd.pkg.mk"
