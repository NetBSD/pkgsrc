# $NetBSD: Makefile,v 1.90 2023/11/08 13:20:48 wiz Exp $
#

DISTNAME=	opendnssec-1.4.14
PKGREVISION=	12
CATEGORIES=	security net
MASTER_SITES=	https://www.opendnssec.org/files/source/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://www.opendnssec.org/
COMMENT=	OSS for a fast and easy DNSSEC deployment
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	CUnit-[0-9]*:../../devel/cunit
DEPENDS+=	ldns>=1.6.17:../../net/ldns

BUILD_DEFS+=	VARBASE

USE_TOOLS+=	bash gmake
CONFIG_SHELL=	${BASH}
USE_LANGUAGES=	c99 c++
USE_LIBTOOL=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

REPLACE_PERL=	enforcer/utils/convert_database.pl
REPLACE_PERL+=	enforcer/utils/migrate_id_mysql.pl
REPLACE_PERL+=	enforcer/utils/migrate_keyshare_mysql.pl
REPLACE_PERL+=	enforcer/utils/migrate_keyshare_sqlite3.pl
REPLACE_PERL+=	enforcer/utils/migrate_to_ng_mysql.pl
REPLACE_PERL+=	enforcer/utils/migrate_to_ng_sqlite.pl

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
PKG_SYSCONFSUBDIR=	opendnssec

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKSRC}/conf/Makefile.in
SUBST_STAGE.paths=	pre-configure
SUBST_VARS.paths=	EGDIR

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
	${INSTALL} ${WRKSRC}/KNOWN_ISSUES ${DESTDIR}${DOCDIR}
	${INSTALL} ${WRKSRC}/MIGRATION ${DESTDIR}${DOCDIR}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../net/ldns/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
