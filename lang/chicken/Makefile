# $NetBSD: Makefile,v 1.34 2008/05/12 20:31:08 degroote Exp $
#

DISTNAME=	chicken-3.2.0
CATEGORIES=	lang
MASTER_SITES=	http://chicken.wiki.br/releases/${PKGVERSION_NOREV}/

MAINTAINER=	asau@inbox.ru #, airhead@users.sourceforge.net
HOMEPAGE=	http://www.call-with-current-continuation.org/
COMMENT=	Scheme to C compiler, handling R5RS

PKG_DESTDIR_SUPPORT=	user-destdir

INFO_FILES=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo
UNLIMIT_RESOURCES=	datasize

INSTALLATION_DIRS=	share/chicken
OWN_DIRS=		${PREFIX}/lib/chicken ${PREFIX}/lib/chicken/3

BUILD_TARGET=		all chicken.info

.include "../../mk/bsd.prefs.mk"

# PLATFORM detection:
.if !empty(OPSYS:M*BSD)
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
MAKE_FLAGS+=	USE_HOST_PCRE=yes

SUBST_CLASSES+=		add-rpath
SUBST_STAGE.add-rpath=	pre-configure
SUBST_FILES.add-rpath=	defaults.make
SUBST_SED.add-rpath=	-e 's|-lpcre|${COMPILER_RPATH_FLAG}${PREFIX}/lib -L${PREFIX}/lib -lpcre|'

TEST_TARGET=	check

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
