# $NetBSD: Makefile,v 1.9 2006/08/17 14:19:00 taca Exp $
#

DISTNAME=	nagios-2.5
PKGNAME=	${DISTNAME:S/-/-base-/}
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nagios/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nagios.org/
COMMENT=	Network monitor

.include "../../mk/bsd.prefs.mk"
.include "../../net/nagios-base/Makefile.common"
.include "options.mk"

CONFIGURE_ARGS+=	--with-gd-lib=${LOCALBASE}/lib		\
			--with-gd-inc=${LOCALBASE}/include	\
			--enable-embedded-perl			\
			--with-perlcache

CONFIGURE_ARGS+=	--with-nagios-user=${NAGIOS_USER:Q}
CONFIGURE_ARGS+=	--with-nagios-grp=${NAGIOS_GROUP:Q}
CONFIGURE_ARGS+=	--with-command-user=${ROOT_USER:Q}
CONFIGURE_ARGS+=	--with-command-grp=${ROOT_GROUP:Q}
CONFIGURE_ARGS+=	--with-init-dir=${PREFIX}/share/examples/rc.d
CONFIGURE_ARGS+=	--with-lockfile=/var/run/nagios/nagios.lock

RCD_SCRIPTS+=		nagios

INSTALL_TARGET=		install install-config

BUILD_DEFS+=	VARBASE

PKG_GROUPS+=	${NAGIOS_GROUP}
PKG_GROUPS+=	${NAGIOSADM_GROUP}

PKG_USERS+=	${NAGIOS_USER}:${NAGIOS_GROUP}
PKG_USERS+=	${NAGIOSADM_USER}:${NAGIOSADM_GROUP}

PKG_GECOS.${NAGIOS_USER}=	Nagios Runtime User
PKG_GECOS.${NAGIOSADM_USER}=	Nagios Administrator
PKG_HOME.${NAGIOSADM_USER}=	${PKG_SYSCONFDIR}
PKG_SHELL.${NAGIOSADM_USER}=	${SH}

EGDIR=		${PREFIX}/share/examples/nagios
EGFILES=	cgi.cfg checkcommands.cfg contactgroups.cfg contacts.cfg	\
		dependencies.cfg escalations.cfg hostgroups.cfg hosts.cfg	\
		misccommands.cfg nagios.cfg resource.cfg services.cfg 		\
		timeperiods.cfg

.for files in ${EGFILES}
CONF_FILES+=	${EGDIR}/${files}-sample ${PKG_SYSCONFDIR}/${files}
.endfor
CONF_FILES+=            ${EGDIR}/nagios.conf ${PKG_SYSCONFDIR}/nagios.conf

NAGIOS_DIRS=	log/nagios log/nagios/archives run/nagios run/nagios/rw
.for dir in ${NAGIOS_DIRS}
OWN_DIRS_PERMS+=	${VARBASE}/${dir} ${NAGIOS_USER} ${NAGIOS_GROUP} 0775
.endfor

SUBST_CLASSES+=		files
SUBST_STAGE.files=	post-build
SUBST_FILES.files=	nagios.conf.dist
SUBST_SED.files=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_MESSAGE.files=	Fixing configuration files.

pre-build:
	${CP} ${FILESDIR}/nagios.conf.dist ${WRKSRC}/nagios.conf.dist

post-install:
	${INSTALL_DATA} ${WRKSRC}/nagios.conf.dist ${EGDIR}/nagios.conf

.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
