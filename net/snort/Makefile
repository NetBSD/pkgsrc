# $NetBSD: Makefile,v 1.36 2008/01/06 00:28:44 adrianp Exp $
#

DISTNAME=		snort-2.8.0.1
CATEGORIES=		net security
MASTER_SITES=		http://www.snort.org/dl/current/

MAINTAINER=		adrianp@NetBSD.org
HOMEPAGE=		http://www.snort.org/
COMMENT=		The Open Source Network Intrusion Detection System

CONFLICTS+=		snort-mysql-[0-9]*
CONFLICTS+=		snort-pgsql-[0-9]*
CONFLICTS+=		snort-prelude-[0-9]*

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
PKG_SYSCONFSUBDIR=	snort
RCD_SCRIPTS=		snort
SNORT_USER?=		snort
SNORT_GROUP?=		snort
EGDIR=			${PREFIX}/share/examples/snort
PKG_GROUPS=		${SNORT_GROUP}
PKG_USERS=		${SNORT_USER}:${SNORT_GROUP}
PKG_GROUPS_VARS+=	SNORT_GROUP
PKG_USERS_VARS+=	SNORT_USER
FILES_SUBST+=		SNORT_USER=${SNORT_USER:Q} SNORT_GROUP=${SNORT_GROUP:Q}
BUILD_DEFS+=		VARBASE
OWN_DIRS_PERMS=		${VARBASE}/log/snort ${SNORT_USER} ${SNORT_GROUP} 700
DOC_FILES=		BUGS INSTALL NEWS PROBLEMS README TODO USAGE WISHLIST

CONF_FILES=		${EGDIR}/snort.conf.default \
			${PKG_SYSCONFDIR}/snort.conf
CONF_FILES+=		${EGDIR}/threshold.conf \
			${PKG_SYSCONFDIR}/threshold.conf
CONF_FILES+=		${EGDIR}/classification.config \
			${PKG_SYSCONFDIR}/classification.config
CONF_FILES+=		${EGDIR}/reference.config \
			${PKG_SYSCONFDIR}/reference.config
CONF_FILES+=		${EGDIR}/gen-msg.map \
			${PKG_SYSCONFDIR}/gen-msg.map
CONF_FILES+=		${EGDIR}/generators \
			${PKG_SYSCONFDIR}/generators
CONF_FILES+=		${EGDIR}/sid-msg.map \
			${PKG_SYSCONFDIR}/sid-msg.map
CONF_FILES+=		${EGDIR}/unicode.map \
			${PKG_SYSCONFDIR}/unicode.map

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	etc/snort.conf src/snort.c
SUBST_SED.paths=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_SED.paths+=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.paths=	Fixing paths.

SUBST_CLASSES+=		install
SUBST_STAGE.install=	post-configure
SUBST_FILES.install=	src/dynamic-preprocessors/ftptelnet/Makefile
SUBST_FILES.install+=	src/dynamic-preprocessors/smtp/Makefile
SUBST_FILES.install+=	src/dynamic-preprocessors/ssh/Makefile
SUBST_FILES.install+=	src/dynamic-preprocessors/dcerpc/Makefile
SUBST_FILES.install+=	src/dynamic-preprocessors/dns/Makefile
SUBST_SED.install=	-e "s|-o root -g wheel||g"
SUBST_MESSAGE.install=	Fixing install scripts.

# does not work on SunOS
.if ${OPSYS} == "SunOS"
PKG_OPTIONS.snort=-inet6
.endif

.include "options.mk"

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-libpcap-includes=${BUILDLINK_PREFIX.libpcap}/include
CONFIGURE_ARGS+=	--with-libpcap-libraries=${BUILDLINK_PREFIX.libpcap}/lib

pre-build:
	${CP} ${WRKSRC}/etc/snort.conf ${WRKSRC}/etc/snort.conf.default

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snort
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snort/schemas

	${INSTALL_DATA} ${WRKSRC}/etc/*.config \
			${WRKSRC}/etc/*.map \
			${WRKSRC}/etc/threshold.conf \
			${WRKSRC}/etc/snort.conf.default ${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/generators ${EGDIR}

.	for i in ${DOC_FILES}
		${INSTALL_DATA}	${WRKSRC}/doc/${i} ${PREFIX}/share/doc/snort/
.	endfor

	${INSTALL_DATA} ${WRKSRC}/doc/README.* ${PREFIX}/share/doc/snort/
	${INSTALL_DATA} ${WRKSRC}/doc/*.tex ${PREFIX}/share/doc/snort/
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${PREFIX}/share/doc/snort/
	${INSTALL_MAN} ${WRKSRC}/snort.8 ${PREFIX}/${PKGMANDIR}/man8

	${INSTALL_DATA} ${WRKSRC}/schemas/create_* \
		${PREFIX}/share/doc/snort/schemas

.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
