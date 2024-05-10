# $NetBSD: Makefile,v 1.74 2024/05/10 19:49:13 jperkin Exp $
#

DISTNAME=		snort-2.9.16.1
PKGREVISION=		6
CATEGORIES=		net security
MASTER_SITES=		https://www.snort.org/downloads/archive/snort/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.snort.org/
COMMENT=		The Open Source Network Intrusion Detection System
LICENSE=		gnu-gpl-v2

DEPENDS+=		daq>=2.0.0:../../net/daq

CONFLICTS+=		snort-mysql-[0-9]*
CONFLICTS+=		snort-pgsql-[0-9]*
CONFLICTS+=		snort-prelude-[0-9]*

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config
USE_TOOLS+=		bash
PKG_SYSCONFSUBDIR=	snort
RCD_SCRIPTS=		snort
SNORT_USER?=		snort
SNORT_GROUP?=		snort
EGDIR=			${PREFIX}/share/examples/snort
PKG_GROUPS=		${SNORT_GROUP}
PKG_USERS=		${SNORT_USER}:${SNORT_GROUP}
PKG_GROUPS_VARS+=	SNORT_GROUP
PKG_USERS_VARS=		SNORT_USER
FILES_SUBST+=		SNORT_USER=${SNORT_USER} SNORT_GROUP=${SNORT_GROUP}
BUILD_DEFS+=		VARBASE
MAKE_JOBS_SAFE=		NO # could not compile it on a multi-core system
OWN_DIRS_PERMS=		${VARBASE}/log/snort ${SNORT_USER} ${SNORT_GROUP} 700
DOC_FILES=		BUGS INSTALL NEWS PROBLEMS README TODO USAGE WISHLIST
OWN_DIRS=		${PKG_SYSCONFDIR} ${PKG_SYSCONFDIR}/rules
OWN_DIRS+=		${PKG_SYSCONFDIR}/so_rules ${PKG_SYSCONFDIR}/preproc_rules
OWN_DIRS+=		${PREFIX}/lib ${PREFIX}/lib/snort_dynamicrules
INSTALLATION_DIRS+=	${EGDIR}/rules
AUTO_MKDIRS=		yes

CONF_FILES=		${EGDIR}/attribute_table.dtd \
			${PKG_SYSCONFDIR}/attribute_table.dtd
CONF_FILES+=		${EGDIR}/classification.config \
			${PKG_SYSCONFDIR}/classification.config
CONF_FILES+=		${EGDIR}/file_magic.conf \
			${PKG_SYSCONFDIR}/file_magic.conf
CONF_FILES+=		${EGDIR}/gen-msg.map \
			${PKG_SYSCONFDIR}/gen-msg.map
CONF_FILES+=		${EGDIR}/reference.config \
			${PKG_SYSCONFDIR}/reference.config
CONF_FILES+=		${EGDIR}/snort.conf.default \
			${PKG_SYSCONFDIR}/snort.conf
CONF_FILES+=		${EGDIR}/threshold.conf \
			${PKG_SYSCONFDIR}/threshold.conf
CONF_FILES+=		${EGDIR}/generators \
			${PKG_SYSCONFDIR}/generators
CONF_FILES+=		${EGDIR}/unicode.map \
			${PKG_SYSCONFDIR}/unicode.map
CONF_FILES+=		${EGDIR}/rules/black_list.rules \
			${PKG_SYSCONFDIR}/rules/black_list.rules
CONF_FILES+=		${EGDIR}/rules/white_list.rules \
			${PKG_SYSCONFDIR}/rules/white_list.rules

REPLACE_BASH+=		tools/appid_detector_builder.sh

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	etc/snort.conf
SUBST_SED.paths=	-e "s|/usr/local|${PREFIX}|g"
SUBST_SED.paths+=	-e "s|../rules|rules|g"
SUBST_SED.paths+=	-e "s|../so_rules|so_rules|g"
SUBST_SED.paths+=	-e "s|../preproc_rules|preproc_rules|g"
SUBST_MESSAGE.paths=	Fixing paths.

SUBST_CLASSES+=		installp
SUBST_STAGE.installp=	post-extract
SUBST_FILES.installp=	src/dynamic-preprocessors/Makefile.in
SUBST_SED.installp=	-e "s|exec_prefix)|exec_prefix)/share/snort|g"
SUBST_MESSAGE.installp=	Fixing preprocessors install path.

.include "options.mk"

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-static-daq
CONFIGURE_ARGS+=	--enable-sourcefire
CONFIGURE_ARGS+=	--with-daq-includes=${BUILDLINK_PREFIX.daq}/include
CONFIGURE_ARGS+=	--with-daq-libraries=${BUILDLINK_PREFIX.daq}/lib
CONFIGURE_ARGS+=	--with-libpcap-includes=${BUILDLINK_PREFIX.libpcap}/include
CONFIGURE_ARGS+=	--with-libpcap-libraries=${BUILDLINK_PREFIX.libpcap}/lib
CONFIGURE_ARGS+=	--disable-so_with_static_lib

TOOL_DEPENDS+=	bison-[0-9]*:../../devel/bison

CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t
CPPFLAGS.SunOS+=	-Du_int16_t=uint16_t
CPPFLAGS.SunOS+=	-Du_int32_t=uint32_t

pre-build:
	${CP} ${WRKSRC}/etc/snort.conf ${WRKSRC}/etc/snort.conf.default

INSTALLATION_DIRS+=	${EGDIR} share/doc/snort/schemas

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/*.config \
			${WRKSRC}/etc/*.map \
			${WRKSRC}/etc/threshold.conf \
			${WRKSRC}/etc/attribute_table.dtd \
			${WRKSRC}/etc/file_magic.conf \
			${WRKSRC}/etc/snort.conf.default ${DESTDIR}${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/generators ${DESTDIR}${EGDIR}

.for i in ${DOC_FILES}
	${INSTALL_DATA}	${WRKSRC}/doc/${i} ${DESTDIR}${PREFIX}/share/doc/snort/
.endfor

	${INSTALL_DATA} ${WRKSRC}/doc/README.* \
			${WRKSRC}/doc/*.tex \
			${WRKSRC}/doc/*.pdf ${DESTDIR}${PREFIX}/share/doc/snort/
	${INSTALL_DATA} ${FILESDIR}/black_list.rules \
			${FILESDIR}/white_list.rules ${DESTDIR}${EGDIR}/rules/
	${INSTALL_MAN} ${WRKSRC}/snort.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

PLIST_VARS+=		appid
.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--disable-open-appid
.else
PLIST.appid=		yes
.include "../../lang/LuaJIT2/buildlink3.mk"
.endif

.include "../../www/nghttp2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/flex/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/daq/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
