# $NetBSD: Makefile,v 1.40 2009/12/15 12:38:04 asau Exp $
#

DISTNAME=	chicken-4.3.0
CATEGORIES=	lang
MASTER_SITES=	http://chicken.wiki.br/releases/${PKGVERSION_NOREV}/ \
		http://galinha.ucpel.tche.br/releases/${PKGVERSION_NOREV}/ \
		${HOMEPAGE}

MAINTAINER=	asau@inbox.ru #, airhead@users.sourceforge.net
HOMEPAGE=	http://www.call-with-current-continuation.org/
COMMENT=	Scheme to C compiler, handling R5RS
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

INFO_FILES=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo
UNLIMIT_RESOURCES=	datasize

INSTALLATION_DIRS=	share/chicken
OWN_DIRS=		${PREFIX}/lib/chicken ${PREFIX}/lib/chicken/4

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
.else
#PLATFORM+=	${OPSYS} == "Interix"
# possible choices left: mingw-msys mingw cygwin cross-linux-mingw
PKG_FAIL_REASON=	"${OPSYS} is not supported"
.endif

MAKE_ENV+=	HOST=	# fix ${HOST} prepending ${CC}
# Need to have these in MAKE_FLAGS, MAKE_ENV is not enough due to the
# way the build system overrides them.
MAKE_FLAGS+=	PLATFORM=${PLATFORM:Q} PREFIX=${PREFIX:Q} DESTDIR=${DESTDIR:Q}
MAKE_FLAGS+=	TOPMANDIR=${PREFIX:Q}/${PKGMANDIR}
MAKE_FLAGS+=	INFODIR=${PREFIX:Q}/${PKGINFODIR:Q}
MAKE_FLAGS+=	DOCDIR=${PREFIX:Q}/share/doc/${PKGNAME_NOREV}

TEST_TARGET=	check

CHECK_PORTABILITY_SKIP += scripts/test-dist.sh

.include "../../mk/bsd.pkg.mk"
