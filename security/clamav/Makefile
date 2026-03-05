# $NetBSD: Makefile,v 1.106 2026/03/05 06:55:33 taca Exp $

.include "cargo-depends.mk"
.include "Makefile.common"

COMMENT=	Anti-virus toolkit

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gsed pkg-config gmake
SET_LIBDIR=		yes
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}
CMAKE_CONFIGURE_ARGS+=	-DAPP_CONFIG_DIRECTORY=${PKG_SYSCONFDIR}
CMAKE_CONFIGURE_ARGS+=	-DDATABASE_DIRECTORY=${CLAMAV_DBDIR}
CMAKE_CONFIGURE_ARGS+=	-DCLAMAV_USER=${CLAMAV_USER}
CMAKE_CONFIGURE_ARGS+=	-DCLAMAV_GROUP=${CLAMAV_GROUP}
CMAKE_CONFIGURE_ARGS+=	-DENABLE_EXTERNAL_MSPACK=on
CMAKE_CONFIGURE_ARGS+=	-DENABLE_TESTS=off
CMAKE_CONFIGURE_ARGS+=	-DENABLE_MILTER=off

CHECK_PORTABILITY_SKIP=	contrib/* unit_tests/* win32/*

.include "../../mk/compiler.mk"

NOT_PAX_MPROTECT_SAFE+=	sbin/clamd
NOT_PAX_MPROTECT_SAFE+=	bin/clamscan
NOT_PAX_MPROTECT_SAFE+=	bin/freshclam

CFLAGS.SunOS+=		-D__EXTENSIONS__
.if ${PKGSRC_COMPILER:Mclang} || ${CC_VERSION:Mgcc-[6-9]*} || ${CC_VERSION:Mgcc-1[0-9].*}
CFLAGS.SunOS+=		-D_XOPEN_SOURCE=600
.endif

.for m in clamdscan libclamav libclamunrar libclamunrar_iface libfreshclam
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/${m}/${m}.map
.endfor

BUILD_DEFS+=	CLAMAV_USER CLAMAV_GROUP CLAMAV_DBDIR
FILES_SUBST+=	CLAMAV_USER=${CLAMAV_USER}
FILES_SUBST+=	CLAMAV_GROUP=${CLAMAV_GROUP}
FILES_SUBST+=	CLAMAV_DBDIR=${CLAMAV_DBDIR}
MESSAGE_SUBST+=	CLAMAV_USER=${CLAMAV_USER}

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	pre-configure
SUBST_FILES.vars=	etc/clamav-milter.conf.sample etc/clamd.conf.sample
SUBST_VARS.vars=	CLAMAV_DBDIR

RCD_SCRIPTS=	clamd freshclamd
SMF_METHODS=	clamd freshclamd
SMF_INSTANCES=	${SMF_METHODS}

PKG_GROUPS+=	${CLAMAV_GROUP}
PKG_USERS+=	${CLAMAV_USER}:${CLAMAV_GROUP}

PKG_GROUPS_VARS+=	CLAMAV_GROUP
PKG_USERS_VARS=		CLAMAV_USER

EGDIR=		${PREFIX}/share/examples/clamav

CONF_SAMPLES=		clamd.conf freshclam.conf

.include "options.mk"

OWN_DIRS_PERMS=		${CLAMAV_DBDIR} ${CLAMAV_USER} ${CLAMAV_GROUP} 0775
CONF_FILES=		# empty
CONF_FILES_PERMS=	# empty
.for i in ${CONF_SAMPLES}
CONF_FILES+=		${EGDIR}/${i} ${PKG_SYSCONFDIR}/${i}
.endfor

INSTALLATION_DIRS+=	${EGDIR}

pre-configure:
	#prevent docs install
	${RM} -r ${WRKSRC}/docs/html

post-install:
.for i in ${CONF_SAMPLES}
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/${i}.sample ${DESTDIR}${EGDIR}/${i}
.endfor

.include "../../devel/cmake/build.mk"
.include "../../lang/rust/cargo.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/libmspack/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
