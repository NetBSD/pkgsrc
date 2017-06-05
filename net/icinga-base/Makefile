# $NetBSD: Makefile,v 1.16 2017/06/05 14:24:16 ryoon Exp $
#

DISTNAME=	icinga-1.9.4
PKGNAME=	${DISTNAME:S/-/-base-/}
PKGREVISION=	9
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icinga/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.icinga.org/
COMMENT=	Enterprise grade open source monitoring system
LICENSE=	gnu-gpl-v2

CONFLICTS=	nagios-base-[0-9]*

.include "../../mk/bsd.prefs.mk"
.include "../../net/icinga-base/Makefile.common"
.include "options.mk"

CONFIGURE_ARGS+=	--with-gd-lib=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-gd-inc=${PREFIX}/include
CONFIGURE_ARGS+=	--enable-embedded-perl
CONFIGURE_ARGS+=	--with-perlcache

CONFIGURE_ARGS+=	--with-icinga-user=${ICINGA_USER}
CONFIGURE_ARGS+=	--with-icinga-group=${ICINGA_GROUP}
CONFIGURE_ARGS+=	--with-command-user=${ICINGA_USER}
CONFIGURE_ARGS+=	--with-command-group=${ICINGACMD_GROUP}
CONFIGURE_ARGS+=	--with-init-dir=${PREFIX}/share/examples/rc.d
CONFIGURE_ARGS+=	--with-lockfile=/var/run/icinga/icinga.lock

USE_TOOLS+=		mail:run perl
CONFIGURE_ARGS+=	--with-mail=${TOOLS_PLATFORM.mail:Q}

RCD_SCRIPTS+=		icinga
FILES_SUBST+=		ICINGA_USER=${ICINGA_USER}

INSTALL_TARGET=		install install-config

BUILD_DEFS+=		VARBASE ICINGA_USER ICINGA_GROUP ICINGACMD_GROUP
BUILD_DEFS+=		ICINGADIR

PKG_GROUPS+=		${ICINGA_GROUP}
PKG_GROUPS+=		${ICINGACMD_GROUP}

PKG_USERS+=		${ICINGA_USER}:${ICINGA_GROUP}

PKG_GECOS.${ICINGA_USER}=	Icinga Runtime User

MESSAGE_SUBST+=		ICINGA_USER=${ICINGA_USER}
MESSAGE_SUBST+=		ICINGACMD_GROUP=${ICINGACMD_GROUP}

EGDIR=			${PREFIX}/share/examples/icinga
EGFILES=		cgi.cfg cgiauth.cfg icinga.cfg icinga.conf
EGFILES+=		objects/commands.cfg objects/contacts.cfg
EGFILES+=		objects/localhost.cfg objects/notifications.cfg
EGFILES+=		objects/printer.cfg objects/switch.cfg
EGFILES+=		objects/templates.cfg objects/timeperiods.cfg
EGFILES+=		objects/windows.cfg resource.cfg

INSTALLATION_DIRS+=	${PKG_SYSCONFDIR}/objects
INSTALLATION_DIRS+=	${PKG_SYSCONFDIR}/modules
INSTALLATION_DIRS+=	${PKG_SYSCONFDIR}/conf.d

.for files in ${EGFILES}
CONF_FILES+=		${EGDIR}/${files} ${PKG_SYSCONFDIR}/${files}
.endfor
CONF_FILES+=		${EGDIR}/icinga.conf ${PKG_SYSCONFDIR}/icinga.conf

OWN_DIRS_PERMS+=${ICINGADIR} ${ICINGA_USER} ${ICINGA_GROUP} 0775
OWN_DIRS_PERMS+=${ICINGADIR}/archives ${ICINGA_USER} ${ICINGA_GROUP} 0775
OWN_DIRS_PERMS+=${ICINGADIR}/rw ${ICINGA_USER} ${ICINGACMD_GROUP} 0775
OWN_DIRS_PERMS+=${ICINGADIR}/checkresults ${ICINGA_USER} ${ICINGACMD_GROUP} 0775

SUBST_CLASSES+=		files
SUBST_STAGE.files=	post-build
SUBST_FILES.files=	icinga.conf.dist
SUBST_SED.files=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_MESSAGE.files=	Fixing configuration files.

pre-build:
	${CP} ${FILESDIR}/icinga.conf.dist ${WRKSRC}/icinga.conf.dist

post-install:
	${INSTALL_DATA} ${WRKSRC}/icinga.conf.dist ${DESTDIR}/${EGDIR}/icinga.conf

.include "../../databases/libdbi/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
