# $NetBSD: Makefile,v 1.107 2025/02/07 15:06:18 adam Exp $

DISTNAME=	rpm-4.20.0
CATEGORIES=	misc
MASTER_SITES=	http://ftp.rpm.org/releases/rpm-${PKGVERSION_NOREV:R}.x/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rpm.org/
COMMENT=	The Red Hat Package Manager
LICENSE=	gnu-lgpl-v2 OR gnu-gpl-v2

CONFLICTS+=		rpm2cpio<1.0nb1

NOT_FOR_PLATFORM+=	Interix-*-* # getmntent() is nonpublic; needs porting

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		bash:run msgfmt perl:run pkg-config gsed
LUA_VERSIONS_ACCEPTED=	54 53 52

CMAKE_CONFIGURE_ARGS+=	-DIntl_INCLUDE_DIR=${PREFIX}/include
CMAKE_CONFIGURE_ARGS+=	-DENABLE_OPENMP=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_PYTHON=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_TESTSUITE=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_ACL=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_AUDIT=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_CAP=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_DBUS=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_LIBDW=OFF
# Requires newer libelf
CMAKE_CONFIGURE_ARGS+=	-DWITH_LIBELF=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_SELINUX=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_SEQUOIA=OFF

PKGCONFIG_OVERRIDE=	rpm.pc.in

REPLACE_BASH+=		installplatform
REPLACE_BASH+=		scripts/brp-compress
REPLACE_BASH+=		scripts/check-prereqs
REPLACE_BASH+=		scripts/check-rpaths-worker
REPLACE_BASH+=		scripts/find-lang.sh
REPLACE_BASH+=		scripts/fontconfig.prov
REPLACE_BASH+=		scripts/ocamldeps.sh
REPLACE_BASH+=		scripts/pkgconfigdeps.sh
REPLACE_BASH+=		scripts/rpm_macros_provides.sh
REPLACE_BASH+=		scripts/sysusers.sh

LDFLAGS+=		${PTHREAD_LDFLAGS}

MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}/man8
MAKE_FLAGS+=		ROOT=${DESTDIR}

RPMDIR=			${RPM_DB_PREFIX}/lib/rpm
FILES_SUBST+=		RPMDIR=${RPMDIR}

CHECK_PORTABILITY_SKIP=	tests/rpmtests

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libelf/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk" # for libmagic
.include "../../mk/bsd.pkg.mk"
