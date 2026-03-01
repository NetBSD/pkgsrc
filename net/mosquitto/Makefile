# $NetBSD: Makefile,v 1.47 2026/03/01 01:03:12 gdt Exp $

DISTNAME=	mosquitto-2.1.2
CATEGORIES=	net
MASTER_SITES=	https://mosquitto.org/files/source/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://mosquitto.org/
COMMENT=	Open Source MQTT broker
LICENSE=	epl-v1.0

USE_LANGUAGES+=		c c++
# Upstream does not document required compiler versions in
# README_compiling.md, but CMakeLists.txt says c99 and c++17
USE_CC_FEATURES=	c99
USE_CXX_FEATURES=	c++17

# \todo File a bug upstream.
LDFLAGS.SunOS+=		-lsocket -lnsl

USE_TOOLS+=		pkg-config

# \todo Consider WITH_DOCS=no.
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

MOSQUITTO_USER=		mosquitto
MOSQUITTO_GROUP=	mosquitto

PKG_USERS=	${MOSQUITTO_USER}:${MOSQUITTO_GROUP}
PKG_GROUPS=	${MOSQUITTO_GROUP}

CONF_FILES=	${PREFIX}/share/examples/mosquitto/mosquitto.conf.example \
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
FILES_SUBST+=	VARBASE=${VARBASE}

BUILD_DEFS+=	VARBASE

PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"

# As of 2.1.0, cmake is the recommended build system.
.include "../../devel/cmake/build.mk"

CMAKE_CONFIGURE_ARGS+=	-DWITH_BUNDLED_DEPS=no

# Somehow, even with WITH_EDITLINE=no, adding this finds it, causing build failures.
# # upstream cmake fails to find libedit.pc
# CMAKE_CONFIGURE_ARGS+=	-DEDITLINE_DIR=${BUILDLINK_PREFIX.editline}
# CMAKE_CONFIGURE_ARGS+=	-DEDITLINE_INCLUDE_DIR=${BUILDLINK_PREFIX.editline}/${BUILDLINK_INCDIRS.editline}

# Upstream editline cmakery cannot handle editline's readline compat as installed natively.
CMAKE_CONFIGURE_ARGS+=	-DWITH_EDITLINE=no

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_SYSCONFDIR=${PREFIX}/share/examples

.include "options.mk"

# Same order as README-compiling.md
.include "../../textproc/cJSON/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../devel/editline/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
# pthreads included above
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/uthash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
