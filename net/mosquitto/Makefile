# $NetBSD: Makefile,v 1.2 2019/08/01 23:40:40 gdt Exp $

VERSION=	1.6.4
DISTNAME=	mosquitto-${VERSION}
CATEGORIES=	net
MASTER_SITES=	https://mosquitto.org/files/source/

#MAINTAINER=	amoibos@gmail.com
MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://mosquitto.org/
COMMENT=	Open Source MQTT broker
LICENSE=	epl-v1.0

USE_LANGUAGES+=	c c++
# Upstream documents that "unix" should use make, but Mac cmake.
# After asking and receiving no guidance, choose to always use cmake.
# https://github.com/eclipse/mosquitto/issues/1041
USE_CMAKE=	yes
USE_TOOLS+=	gmake

CMAKE_ARGS+=	-DCMAKE_INSTALL_SYSCONFDIR=${PREFIX}/share/examples

MOSQUITTO_USER=		mosquitto
MOSQUITTO_GROUP=	mosquitto

PKG_USERS=	${MOSQUITTO_USER}:${MOSQUITTO_GROUP}
PKG_GROUPS=	${MOSQUITTO_GROUP}

# \todo The example file is vast and arguably should not be installed.
# However, we need to set a few things to make automatic startup work.
CONF_FILES=	${PREFIX}/share/examples/mosquitto/mosquitto.conf \
		${PKG_SYSCONFDIR}/mosquitto.conf

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_MESSAGE.paths=	Substituting paths
SUBST_FILES.paths=	mosquitto.conf
SUBST_SED.paths=	-e "s,@SSLCERTS@,${SSLCERTS},g"

RCD_SCRIPTS=	mosquitto
FILES_SUBST+=	MOSQUITTO_USER=${MOSQUITTO_USER}
FILES_SUBST+=	MOSQUITTO_GROUP=${MOSQUITTO_GROUP}
FILES_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

# mosquitto's build system is very troubled, and the tests do not
# currently work.
#   https://github.com/eclipse/mosquitto/issues/1242
#   https://github.com/eclipse/mosquitto/issues/1330
#
# \todo invoke "gmake test" in tests/ subdir instead of at top level
# \todo pass in CPPFLAGS/LDFLAGS to test invocation
TEST_TARGET=	test
.include "../../devel/cunit/buildlink3.mk"

.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/uthash/buildlink3.mk"
# ?needed
.include "../../net/libcares/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
