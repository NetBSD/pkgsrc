# $NetBSD: Makefile,v 1.2 2019/07/02 13:22:40 ryoon Exp $

DISTNAME=	chicken-5.1.0
CATEGORIES=	lang
MASTER_SITES=	http://code.call-cc.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.call-cc.org/
COMMENT=	Scheme to C compiler, handling R5RS
LICENSE=	modified-bsd

MAKE_JOBS_SAFE=	no

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
UNLIMIT_RESOURCES=	datasize

OWN_DIRS=		${PREFIX}/lib/chicken ${PREFIX}/lib/chicken/9

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
# possible choices left: aix android cross-linux-mingw cygwin hurd mingw
#                        mingw-msys
PKG_SKIP_REASON+=	"${OPSYS} is not supported"
.endif

MAKE_FILE=	GNUmakefile
MAKE_ENV+=	C_COMPILER=${CC:Q}
MAKE_ENV+=	HOST=	# fix ${HOST} prepending ${CC}
# Need to have these in MAKE_FLAGS, MAKE_ENV is not enough due to the
# way the build system overrides them.
MAKE_FLAGS+=	PLATFORM=${PLATFORM:Q} PREFIX=${PREFIX:Q} DESTDIR=${DESTDIR:Q}
MAKE_FLAGS+=	MANDIR=${PREFIX:Q}/${PKGMANDIR}
MAKE_FLAGS+=	INFODIR=${PREFIX:Q}/${PKGINFODIR:Q}
MAKE_FLAGS+=	DOCDIR=${PREFIX:Q}/share/doc/${PKGNAME_NOREV}
MAKE_FLAGS+=	INSTALL_PROGRAM=${INSTALL:Q}

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
