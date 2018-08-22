# $NetBSD: Makefile,v 1.15 2018/08/22 09:45:34 wiz Exp $

DISTNAME=		sqlgrey-1.8.0
PKGREVISION=		4
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sqlgrey/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sqlgrey.sourceforge.net/
COMMENT=		Postfix greylisting policy daemon
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		perl:run

DEPENDS+=		p5-Net-Server>=0.87:../../net/p5-Net-Server
DEPENDS+=		p5-IO-Multiplex>=1:../../devel/p5-IO-Multiplex

# update_sqlgrey_config relies on diff, md5sum and wget
USE_TOOLS+=		diff:run wget:run
DEPENDS+=		coreutils-[0-9]*:../../sysutils/coreutils

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		VARBASE SQLGREY_DIR SQLGREY_PIDDIR
BUILD_DEFS+=		SQLGREY_USER SQLGREY_GROUP

SQLGREY_USER?=		sqlgrey
SQLGREY_GROUP?=		sqlgrey
SQLGREY_DIR?=		${VARBASE}/db/sqlgrey
SQLGREY_PIDDIR?=	${VARBASE}/run

PKG_USERS+=			${SQLGREY_USER}:${SQLGREY_GROUP}
PKG_GROUPS+=			${SQLGREY_GROUP}
PKG_HOME.${SQLGREY_USER}=	${SQLGREY_DIR}

PKG_USERS_VARS=		SQLGREY_USER
PKG_GROUPS_VARS=	SQLGREY_GROUP

OWN_DIRS_PERMS+=	${SQLGREY_DIR} ${SQLGREY_USER} ${SQLGREY_GROUP} 0755

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
INSTALLATION_DIRS+=	share/doc/sqlgrey

PKG_SYSCONFSUBDIR=	${PKGBASE}
RCD_SCRIPTS=		sqlgrey

CONFIG_FILES=		sqlgrey.conf					\
			clients_fqdn_whitelist clients_ip_whitelist	\
			discrimination.regexp dyn_fqdn.regexp		\
			smtp_server.regexp

DOC_FILES=		FAQ HOWTO README README.DBCLUSTER		\
			README.DISCRIMINATION README.OPTINOUT		\
			README.PERF

.for file in ${CONFIG_FILES}
CONF_FILES+=		${EGDIR}/${file} ${PKG_SYSCONFDIR}/${file}
.endfor

REPLACE_PERL=		sqlgrey-logstats.pl
REPLACE_PERL+=		sqlgrey
REPLACE_SH=		update_sqlgrey_config

SUBST_CLASSES+=		sysconfdir
SUBST_STAGE.sysconfdir=	pre-configure
SUBST_FILES.sysconfdir=	sqlgrey update_sqlgrey_config etc/sqlgrey.conf
SUBST_VARS.sysconfdir=	PKG_SYSCONFDIR SQLGREY_PIDDIR
SUBST_VARS.sysconfdir+=	SQLGREY_USER SQLGREY_GROUP

FILES_SUBST+=		SQLGREY_USER=${SQLGREY_USER}
FILES_SUBST+=		SQLGREY_GROUP=${SQLGREY_GROUP}

MAKE_ENV+=		EGDIR=${EGDIR}

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/share/examples/sqlgrey/README
.for file in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/share/doc/sqlgrey
.endfor

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
