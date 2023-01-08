# $NetBSD: Makefile,v 1.6 2023/01/08 21:21:03 gdt Exp $

DISTNAME=	guile-3.0.8
PKGNAME=	${DISTNAME:S/guile/guile30/}
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.gnu.org/gnu/guile/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/guile/
COMMENT=	Official extension language for the GNU operating system
LICENSE=	gnu-lgpl-v3

# Currently, all versions are namespaced.
GUILE_SUBDIR=	guile/3.0
#GUILE_SUBDIR=	# empty

# guile does not like the --build and --host triplets on NetBSD
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	SHELL=${CONFIG_SHELL}
# Needed to work around broken configure check for accept4()
LDFLAGS.SunOS+=		-lsocket -lnsl
MAKE_ENV+=		PAXCTL=echo
MAKE_ENV.NetBSD+=	PAXCTL=/usr/sbin/paxctl

CONFIGURE_ARGS+=	--disable-lto

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

INFO_FILES=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
USE_TOOLS.Darwin+=	gsed
USE_TOOLS.SunOS+=	gsed

PKGCONFIG_OVERRIDE+=	meta/guile-3.0.pc.in
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
GUILE_LIBNAME.*=	so.1.4.1

PLIST_SUBST+=		GUILE_LIBNAME=${GUILE_LIBNAME}
PRINT_PLIST_AWK+=	{gsub(/${GUILE_LIBNAME}/, "$${GUILE_LIBNAME}");}

.include "../../mk/pax.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
# needs threaded boehm-gc
BUILDLINK_API_DEPENDS.boehm-gc+=	boehm-gc>=8.0.4nb1
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
