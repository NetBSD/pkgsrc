# $NetBSD: Makefile,v 1.47 2012/10/03 12:12:45 asau Exp $

DISTNAME=	chicken-4.8.0
CATEGORIES=	lang
MASTER_SITES=	http://code.call-cc.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	asau@inbox.ru #, airhead@users.sourceforge.net
HOMEPAGE=	http://www.call-cc.org/
COMMENT=	Scheme to C compiler, handling R5RS
LICENSE=	modified-bsd

MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
UNLIMIT_RESOURCES=	datasize

INSTALLATION_DIRS=	share/chicken
OWN_DIRS=		${PREFIX}/lib/chicken ${PREFIX}/lib/chicken/6

BUILD_TARGET=		all

.include "../../mk/bsd.prefs.mk"

# PLATFORM detection:
.if !empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly"
PLATFORM=	bsd
.elif ${OPSYS} == "Linux"
PLATFORM=	linux
.elif ${OPSYS} == "Darwin"
PLATFORM=	macosx
.elif ${OPSYS} == "SunOS"
PLATFORM=	solaris
.elif ${OPSYS} == "Haiku"
PLATFORM=	haiku
.else
#PLATFORM+=	${OPSYS} == "Interix"
# possible choices left: mingw-msys mingw cygwin cross-linux-mingw
PKG_FAIL_REASON=	"${OPSYS} is not supported"
.endif

MAKE_FILE=	GNUmakefile
MAKE_ENV+=	C_COMPILER=$(CC:Q)
MAKE_ENV+=	HOST=	# fix ${HOST} prepending ${CC}
# Need to have these in MAKE_FLAGS, MAKE_ENV is not enough due to the
# way the build system overrides them.
MAKE_FLAGS+=	PLATFORM=${PLATFORM:Q} PREFIX=${PREFIX:Q} DESTDIR=${DESTDIR:Q}
MAKE_FLAGS+=	TOPMANDIR=${PREFIX:Q}/${PKGMANDIR}
MAKE_FLAGS+=	INFODIR=${PREFIX:Q}/${PKGINFODIR:Q}
MAKE_FLAGS+=	DOCDIR=${PREFIX:Q}/share/doc/${PKGNAME_NOREV}

TEST_TARGET=	check	# works only after installation

.include "../../mk/bsd.pkg.mk"
