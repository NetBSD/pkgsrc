# $NetBSD: Makefile,v 1.8 2020/11/05 09:09:03 ryoon Exp $
#

DISTNAME=	opendnssec-2.1.7
PKGNAME=	${DISTNAME:S/opendnssec/opendnssec2/}
PKGREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	https://www.opendnssec.org/files/source/

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://www.opendnssec.org/
COMMENT=	OSS for a fast and easy DNSSEC deployment
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	CUnit-[0-9]*:../../devel/cunit
DEPENDS+=	ldns>=1.6.17:../../net/ldns

# Uses the same package name, but is not a full drop-in replacement for...
CONFLICTS+=	opendnssec-1.*

BUILD_DEFS+=	VARBASE

USE_TOOLS+=	bash gmake
CONFIG_SHELL=	${BASH}
USE_LANGUAGES=	c99 c++
USE_LIBTOOL=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

CONVERT_DIR=	enforcer/utils/1.4-2.0_db_convert
REPLACE_BASH+=	${CONVERT_DIR}/convert_mysql
REPLACE_BASH+=	${CONVERT_DIR}/convert_sqlite

ODS_USER?=	opendnssec
ODS_GROUP?=	opendnssec

PKG_GROUPS=		${ODS_GROUP}
PKG_USERS=		${ODS_USER}:${ODS_GROUP}
PKG_GECOS.${ODS_USER}=	OpenDNSSEC user
PKG_HOME.${ODS_USER}=	${VARBASE}/opendnssec
PKG_SHELL.${ODS_USER}=	${SH}
PKG_USERS_VARS+=	ODS_USER
PKG_GROUPS_VARS+=	ODS_GROUP

EGDIR=			${PREFIX}/share/examples/opendnssec
DOCDIR=			${PREFIX}/share/doc/opendnssec
MIGRATEDIR=		${PREFIX}/lib/opendnssec
PKG_SYSCONFSUBDIR=	opendnssec

MIGRATE_FILES+=		README.md convert_mysql convert_sqlite
MIGRATE_FILES+=		find_problematic_zones.sql mysql_convert.sql
MIGRATE_FILES+=		sqlite_convert.sql

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKSRC}/conf/Makefile.in
SUBST_STAGE.paths=	pre-configure
SUBST_VARS.paths=	EGDIR

# Prepare files for installation
SUBST_CLASSES+=		migrate
SUBST_FILES.migrate+=	${WRKSRC}/${CONVERT_DIR}/convert_sqlite
SUBST_FILES.migrate+=	${WRKSRC}/${CONVERT_DIR}/convert_mysql
SUBST_STAGE.migrate=	pre-configure
SUBST_SED.migrate=	-e 's,SCHEMA=../../src/db/,SCHEMA=./,'

CXXFLAGS.NetBSD+=	-D_NETBSD_SOURCE

CONF_FILES+=	${EGDIR}/addns.xml.sample \
			${PKG_SYSCONFDIR}/addns.xml
CONF_FILES+=	${EGDIR}/conf.xml.sample \
			${PKG_SYSCONFDIR}/conf.xml
CONF_FILES+=	${EGDIR}/kasp.xml.sample \
			${PKG_SYSCONFDIR}/kasp.xml
CONF_FILES+=	${EGDIR}/zonelist.xml.sample \
			${PKG_SYSCONFDIR}/zonelist.xml

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR}
INSTALLATION_DIRS+=	share/opendnssec
INSTALLATION_DIRS+=	lib/opendnssec
INSTALLATION_DIRS+=	lib/opendnssec/signer
INSTALLATION_DIRS+=	lib/opendnssec/kasp_auditor
OWN_DIRS+=		${VARBASE}/opendnssec
OWN_DIRS+=		${VARBASE}/opendnssec/tmp
OWN_DIRS+=		${VARBASE}/opendnssec/signconf
OWN_DIRS+=		${VARBASE}/opendnssec/signed
OWN_DIRS+=		${VARBASE}/opendnssec/unsigned

RCD_SCRIPTS=		opendnssec

.include "options.mk"

pre-install:
	${MKDIR} ${DESTDIR}${PKG_SYSCONFDIR}

post-install:
	for f in ${MIGRATE_FILES}; do \
		${INSTALL} ${WRKSRC}/enforcer/utils/1.4-2.0_db_convert/$$f \
			${DESTDIR}/${MIGRATEDIR}; \
	done
	${INSTALL} ${WRKSRC}/enforcer/src/db/schema.mysql \
		${DESTDIR}/${MIGRATEDIR}
	${INSTALL} ${WRKSRC}/enforcer/src/db/schema.sqlite \
		${DESTDIR}/${MIGRATEDIR}

USE_BUILTIN.sqlite3=NO
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../net/ldns/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
