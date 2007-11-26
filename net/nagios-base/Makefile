# $NetBSD: Makefile,v 1.16 2007/11/26 22:14:13 seb Exp $
#

DISTNAME=		nagios-2.5
PKGNAME=		${DISTNAME:S/-/-base-/}
PKGREVISION=		4
CATEGORIES=		net sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=nagios/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nagios.org/
COMMENT=		Network monitor

.include "../../mk/bsd.prefs.mk"
.include "../../net/nagios-base/Makefile.common"
.include "options.mk"

CONFIGURE_ARGS+=	--with-gd-lib=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-gd-inc=${LOCALBASE}/include
CONFIGURE_ARGS+=	--enable-embedded-perl
CONFIGURE_ARGS+=	--with-perlcache

CONFIGURE_ARGS+=	--with-nagios-user=${NAGIOS_USER:Q}
CONFIGURE_ARGS+=	--with-nagios-group=${NAGIOS_GROUP:Q}
CONFIGURE_ARGS+=	--with-command-user=${NAGIOS_USER:Q}
CONFIGURE_ARGS+=	--with-command-group=${NAGIOSCMD_GROUP:Q}
CONFIGURE_ARGS+=	--with-init-dir=${PREFIX}/share/examples/rc.d
CONFIGURE_ARGS+=	--with-lockfile=/var/run/nagios.lock

USE_TOOLS+=		mail:run perl
CONFIGURE_ARGS+=	--with-mail=${TOOLS_PLATFORM.mail}

RCD_SCRIPTS+=		nagios

INSTALL_TARGET=		install install-config

BUILD_DEFS+=		VARBASE

PKG_GROUPS+=		${NAGIOS_GROUP}
PKG_GROUPS+=		${NAGIOSCMD_GROUP}

PKG_USERS+=		${NAGIOS_USER}:${NAGIOS_GROUP}

PKG_GECOS.${NAGIOS_USER}=	Nagios Runtime User

MESSAGE_SUBST+=		NAGIOS_USER=${NAGIOS_USER}
MESSAGE_SUBST+=		NAGIOSCMD_GROUP=${NAGIOSCMD_GROUP}

EGDIR=			${PREFIX}/share/examples/nagios
EGFILES=		cgi.cfg checkcommands.cfg minimal.cfg
EGFILES+=		misccommands.cfg nagios.cfg resource.cfg

.for files in ${EGFILES}
CONF_FILES+=		${EGDIR}/${files}-sample ${PKG_SYSCONFDIR}/${files}
.endfor
CONF_FILES+=		${EGDIR}/nagios.conf ${PKG_SYSCONFDIR}/nagios.conf

OWN_DIRS_PERMS+=${NAGIOSDIR} ${NAGIOS_USER} ${NAGIOS_GROUP} 0775
OWN_DIRS_PERMS+=${NAGIOSDIR}/archives ${NAGIOS_USER} ${NAGIOS_GROUP} 0775
OWN_DIRS_PERMS+=${NAGIOSDIR}/rw ${NAGIOS_USER} ${NAGIOSCMD_GROUP} 0775

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
