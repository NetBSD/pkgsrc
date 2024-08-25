# $NetBSD: Makefile,v 1.9 2024/08/25 06:18:57 wiz Exp $

.include "../../lang/swi-prolog-lite/Makefile.common"

PKGNAME=		swi-prolog-jpl-${SWIPLVERS}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		JPL package for SWI Prolog

USE_TOOLS+=		pkg-config

# does not find JNI for java>=11
PKG_JVMS_ACCEPTED=	kaffe openjdk8 sun-jdk7 oracle-jdk8

CMAKE_CONFIGURE_ARGS+=		-DSWIPL_PACKAGES_JAVA=ON
CMAKE_CONFIGURE_ARGS+=		-DINSTALL_PACKAGES=OFF
CMAKE_CONFIGURE_ARGS+=		-DINSTALL_DOCUMENTATION=OFF

# Part of swi-prolog-lite
CMAKE_CONFIGURE_ARGS+=		-DSWIPL_PACKAGES_ARCHIVE=OFF
CMAKE_CONFIGURE_ARGS+=		-DSWIPL_PACKAGES_BASIC=OFF
CMAKE_CONFIGURE_ARGS+=		-DSWIPL_PACKAGES_SSL=OFF
CMAKE_CONFIGURE_ARGS+=		-DSWIPL_PACKAGES_TERM=OFF

# Part of swi-prolog-packages
CMAKE_CONFIGURE_ARGS+=		-DSWIPL_PACKAGES_X=OFF

SWIPL_PACKAGES_COMPONENTS+=	Java_interface

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
.include "../../mk/java-vm.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
