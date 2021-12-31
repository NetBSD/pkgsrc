# $NetBSD: Makefile,v 1.27 2021/12/31 09:57:35 triaxx Exp $

DISTNAME=	mosquitto-2.0.14
CATEGORIES=	net
MASTER_SITES=	https://mosquitto.org/files/source/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://mosquitto.org/
COMMENT=	Open Source MQTT broker
LICENSE=	epl-v1.0

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

USE_LANGUAGES+=	c c++
# Upstream documents that "unix" should use make, but Mac cmake.
# After asking and receiving no guidance, choose to always use cmake.
# https://github.com/eclipse/mosquitto/issues/1041
USE_CMAKE=	yes
USE_TOOLS+=	gmake

LDFLAGS.SunOS+=	-lsocket -lnsl
CMAKE_ARGS+=	-DCMAKE_INSTALL_SYSCONFDIR=${PREFIX}/share/examples
CMAKE_ARGS+=	-DWITH_PLUGINS=NO

MOSQUITTO_USER=		mosquitto
MOSQUITTO_GROUP=	mosquitto

PKG_USERS=	${MOSQUITTO_USER}:${MOSQUITTO_GROUP}
PKG_GROUPS=	${MOSQUITTO_GROUP}

CONF_FILES=	${PREFIX}/share/examples/mosquitto/mosquitto.conf \
		${PKG_SYSCONFDIR}/mosquitto.conf

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-configure
SUBST_MESSAGE.paths=	Substituting paths
SUBST_FILES.paths=	mosquitto.conf
SUBST_VARS.paths=	SSLCERTS VARBASE

RCD_SCRIPTS=	mosquitto
SMF_METHODS=	mosquitto
FILES_SUBST+=	MOSQUITTO_USER=${MOSQUITTO_USER}
FILES_SUBST+=	MOSQUITTO_GROUP=${MOSQUITTO_GROUP}
FILES_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
FILES_SUBST+= VARBASE=${VARBASE}

PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"

# mosquitto's build system is very troubled, and the tests do not
# currently work.
#   https://github.com/eclipse/mosquitto/issues/1242
#   https://github.com/eclipse/mosquitto/issues/1330
#
# \todo invoke "gmake test" in tests/ subdir instead of at top level
# \todo pass in CPPFLAGS/LDFLAGS to test invocation
TEST_TARGET=	test
.include "../../devel/cunit/buildlink3.mk"

.include "options.mk"   
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/uthash/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
