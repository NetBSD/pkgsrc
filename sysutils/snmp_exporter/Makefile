# $NetBSD: Makefile,v 1.7 2024/06/13 13:47:10 bsiegert Exp $

DISTNAME=	snmp_exporter-0.26.0
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=prometheus/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/prometheus/snmp_exporter/
COMMENT=	SNMP Exporter for Prometheus
LICENSE=	apache-2.0

SUBST_CLASSES+=		path
SUBST_SED.path+=	-e 's|-L/usr/local/lib|-L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib|'
SUBST_SED.path+=	-e 's,/usr/local,${PREFIX},'
SUBST_FILES.path+=	generator/net_snmp.go
SUBST_MESSAGE.path=	Fixing path to includes and libraries.
SUBST_STAGE.path=	pre-configure

LOGDIR=				${VARBASE}/log/snmp_exporter
SNMP_EXPORTER_USER?=		snmp_exporter
SNMP_EXPORTER_GROUP?=		snmp_exporter
OWN_DIRS_PERMS+=		${LOGDIR} ${SNMP_EXPORTER_USER} ${SNMP_EXPORTER_GROUP} 0700
PKG_USERS_VARS+=		SNMP_EXPORTER_USER
PKG_GROUPS_VARS+=		SNMP_EXPORTER_GROUP
PKG_GROUPS=			${SNMP_EXPORTER_GROUP}
PKG_USERS=			${SNMP_EXPORTER_USER}:${SNMP_EXPORTER_GROUP}
RCD_SCRIPTS=			snmp_exporter

FILES_SUBST+=		SNMP_EXPORTER_USER=${SNMP_EXPORTER_USER:Q}
FILES_SUBST+=		SNMP_EXPORTER_GROUP=${SNMP_EXPORTER_GROUP:Q}
FILES_SUBST+=		LOGDIR=${LOGDIR:Q}

BUILD_DEFS+=		VARBASE

INSTALLATION_DIRS+=	share/doc/snmp_exporter
INSTALLATION_DIRS+=	share/examples/snmp_exporter

CONF_FILES+=		share/examples/snmp_exporter/snmp.yml ${PKG_SYSCONFDIR}/snmp.yml

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/snmp_exporter
	${INSTALL_DATA} ${WRKSRC}/snmp.yml ${DESTDIR}${PREFIX}/share/examples/snmp_exporter

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
