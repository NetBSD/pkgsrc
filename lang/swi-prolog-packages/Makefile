# $NetBSD: Makefile,v 1.56 2023/10/24 22:09:40 wiz Exp $

PKGREVISION= 4
.include "../../lang/swi-prolog-lite/Makefile.common"

PKGNAME=		swi-prolog-packages-${SWIPLVERS}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Packages for SWI Prolog

USE_TOOLS+=		pkg-config

CMAKE_ARGS+=		-DINSTALL_PACKAGES=ON
CMAKE_ARGS+=		-DINSTALL_DOCUMENTATION=ON

# Part of swi-prolog-lite
CMAKE_ARGS+=		-DSWIPL_PACKAGES_BASIC=OFF
CMAKE_ARGS+=		-DSWIPL_PACKAGES_SSL=OFF
CMAKE_ARGS+=		-DSWIPL_PACKAGES_TERM=OFF

# Part of swi-prolog-lite... ...but needed to build documentation.
CMAKE_ARGS+=		-DSWIPL_PACKAGES_ARCHIVE=ON

# Part of swi-prolog-jpl
CMAKE_ARGS+=		-DSWIPL_PACKAGES_JAVA=OFF

SWIPL_PACKAGES_COMPONENTS+=	Graphics_subsystem

.include "../../mk/bsd.prefs.mk"

CPPFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS

TEST_TARGET=	check

do-install:
.for component in ${SWIPL_PACKAGES_COMPONENTS}
	cd ${WRKSRC}/build &&						\
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV}			\
		${CMAKE} -DCMAKE_INSTALL_COMPONENT=${component:Q}	\
			-P cmake_install.cmake
.endfor

.include "../../lang/swi-prolog-lite/buildlink3.mk"
BUILDLINK_DEPMETHOD.libarchive=	build
.include "../../archivers/libarchive/buildlink3.mk"
BUILDLINK_DEPMETHOD.ossp-uuid=	build
.include "../../devel/ossp-uuid/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
BUILDLINK_DEPMETHOD.openssl=	build
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
