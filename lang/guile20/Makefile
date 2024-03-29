# $NetBSD: Makefile,v 1.21 2024/03/01 06:34:45 kim Exp $

DISTNAME=	guile-2.0.14
PKGNAME=	${DISTNAME:S/guile/guile20/}
PKGREVISION=	6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=guile/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://www.gnu.org/software/guile/
COMMENT=	Official extension language for the GNU operating system (2.0 branch)
LICENSE=	gnu-lgpl-v3

# Currently, all versions are namespaced.
GUILE_SUBDIR=	guile/2.0
#GUILE_SUBDIR=	# empty

# guile does not like the --build and --host triplets on NetBSD
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-shared
# not until boehm-gc is threaded
CONFIGURE_ARGS+=	--without-threads
CONFIGURE_ARGS+=	SHELL=${CONFIG_SHELL}

.if !empty(GUILE_SUBDIR)
# Installation prefix is non-default.
GUILE_PREFIX=			${PREFIX}/${GUILE_SUBDIR}
CONFIGURE_ARGS+=		--prefix=${GUILE_PREFIX:Q}
CONFIGURE_ARGS+=		--infodir=${GUILE_PREFIX:Q}/info
CONFIGURE_ARGS+=		--mandir=${GUILE_PREFIX:Q}/man
BUILDLINK_PASSTHRU_DIRS+=	${GUILE_PREFIX}
LDFLAGS+=			${COMPILER_RPATH_FLAG}${GUILE_PREFIX}/lib
.else
CONFIGURE_ARGS+=		--prefix=${PREFIX}
CONFIGURE_ARGS+=		--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=		--mandir=${PREFIX}/${PKGMANDIR}
.endif

INFO_FILES=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	meta/guile-2.0.pc.in
# known broken: test-loose-ends on NetBSD/current
# https://debbugs.gnu.org/cgi/bugreport.cgi?bug=24003
TEST_TARGET=		check

SUBST_CLASSES+=		tools
SUBST_SED.tools+=	-e "s,\\((define %pkg-config-program .\\).*\\(.)\\),\\1${PREFIX}/bin/pkg-config\\2,"
SUBST_STAGE.tools=	post-build
SUBST_FILES.tools+=	meta/guile-config
SUBST_MESSAGE.tools=	Fixing path to pkg-config in installed file.

# XXX: less tests would fail if we made libunistring use GNU iconv too
#USE_GNU_ICONV=		yes

OPSYSVARS+=		GUILE_LIBNAME
GUILE_LIBNAME.Darwin=	a
GUILE_LIBNAME.*=	so.22.8.1

PLIST_SUBST+=		GUILE_LIBNAME=${GUILE_LIBNAME}
PRINT_PLIST_AWK+=	{gsub(/${GUILE_LIBNAME}/, "$${GUILE_LIBNAME}");}

# https://debbugs.gnu.org/cgi/bugreport.cgi?bug=24002
post-configure:
	${ECHO} '#define FLEXIBLE_ARRAY_MEMBER /**/' >> ${WRKSRC}/config.h

.include "../../devel/gmp/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
# needs a particular bug fix on NetBSD
BUILDLINK_API_DEPENDS.boehm-gc+=	boehm-gc>=7.4.2nb1
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
#.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
