# $NetBSD: Makefile,v 1.3 2010/02/04 02:43:52 joerg Exp $

DISTNAME=		sqlgrey-1.6.8
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sqlgrey/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sqlgrey.sourceforge.net/
COMMENT=		Postfix greylisting policy daemon

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		perl:run

DEPENDS+=		p5-Net-Server>=0.87:../../net/p5-Net-Server
DEPENDS+=		p5-IO-Multiplex>=1:../../devel/p5-IO-Multiplex

PKG_SYSCONFSUBDIR=	${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

.include "../../mk/bsd.prefs.mk"

SQLGREY_USER?=		sqlgrey
SQLGREY_GROUP?=		sqlgrey

PKG_USERS=		${SQLGREY_USER}:${SQLGREY_GROUP}
PKG_GROUPS=		${SQLGREY_GROUP}

RCD_SCRIPTS=		sqlgrey

MAKE_ENV+=		EGDIR=${EGDIR}

CONF_FILES=		${EGDIR}/clients_fqdn_whitelist	\
			${PKG_SYSCONFDIR}/clients_fqdn_whitelist
CONF_FILES+=		${EGDIR}/clients_ip_whitelist	\
			${PKG_SYSCONFDIR}/clients_ip_whitelist
CONF_FILES+=		${EGDIR}/dyn_fqdn.regexp	\
			${PKG_SYSCONFDIR}/dyn_fqdn.regexp
CONF_FILES+=		${EGDIR}/smtp_server.regexp	\
			${PKG_SYSCONFDIR}/smtp_server.regexp
CONF_FILES+=		${EGDIR}/sqlgrey.conf		\
			${PKG_SYSCONFDIR}/sqlgrey.conf

REPLACE_PERL=		sqlgrey-logstats.pl
REPLACE_PERL+=		sqlgrey
REPLACE_SH=		update_sqlgrey_config

SUBST_CLASSES+=		sysconfdir
SUBST_STAGE.sysconfdir=	pre-configure
SUBST_FILES.sysconfdir=	sqlgrey update_sqlgrey_config etc/sqlgrey.conf
SUBST_SED.sysconfdir=	-e 's,%%PKG_SYSCONFDIR%%,${PKG_SYSCONFDIR},g'
SUBST_SED.sysconfdir+=	-e 's,%%VARBASE%%,${VARBASE},g'
SUBST_SED.sysconfdir+=	-e 's,%%SQLGREY_USER%%,${SQLGREY_USER},g'
SUBST_SED.sysconfdir+=	-e 's,%%SQLGREY_GROUP%%,${SQLGREY_GROUP},g'

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		SQLGREY_USER SQLGREY_GROUP

PKG_USERS_VARS=		SQLGREY_USER
PKG_GROUPS_VARS=	SQLGREY_GROUP

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
