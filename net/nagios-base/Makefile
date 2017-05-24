# $NetBSD: Makefile,v 1.68 2017/05/24 07:42:39 manu Exp $
#

DISTNAME=		nagios-4.3.2
PKGNAME=		${DISTNAME:S/-/-base-/}
#PKGREVISION=		1
CATEGORIES=		net sysutils
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=nagios/}
DISTFILES+=		nagios-netbsd40-icons.tar.gz
SITES.nagios-netbsd40-icons.tar.gz= ${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nagios.org/
COMMENT=		Network monitor
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"
.include "../../net/nagios-base/Makefile.common"
.include "options.mk"

USE_GCC_RUNTIME=	yes

CONFIGURE_ARGS+=	--with-gd-lib=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-gd-inc=${PREFIX}/include
CONFIGURE_ARGS+=	--enable-embedded-perl
CONFIGURE_ARGS+=	--with-perlcache

CONFIGURE_ARGS+=	--with-nagios-user=${NAGIOS_USER}
CONFIGURE_ARGS+=	--with-nagios-group=${NAGIOS_GROUP}
CONFIGURE_ARGS+=	--with-command-user=${NAGIOS_USER}
CONFIGURE_ARGS+=	--with-command-group=${NAGIOSCMD_GROUP}
CONFIGURE_ARGS+=	--with-init-dir=${PREFIX}/share/examples/rc.d
CONFIGURE_ARGS+=	--with-lockfile=/var/run/nagios/nagios.lock

USE_TOOLS+=		mail:run perl
CONFIGURE_ARGS+=	--with-mail=${TOOLS_PLATFORM.mail:Q}

RCD_SCRIPTS+=		nagios
SMF_NAME=		nagios
FILES_SUBST+=		NAGIOS_USER=${NAGIOS_USER}
FILES_SUBST+=		NAGIOS_GROUP=${NAGIOS_GROUP}
FILES_SUBST+=		NAGIOSDIR=${NAGIOSDIR}

INSTALL_TARGET=		install install-config

BUILD_DEFS+=		VARBASE NAGIOS_USER NAGIOS_GROUP NAGIOSCMD_GROUP
BUILD_DEFS+=		NAGIOSDIR

PKG_GROUPS+=		${NAGIOS_GROUP}
PKG_GROUPS+=		${NAGIOSCMD_GROUP}

PKG_USERS+=		${NAGIOS_USER}:${NAGIOS_GROUP}

PKG_GECOS.${NAGIOS_USER}=	Nagios Runtime User

MESSAGE_SUBST+=		NAGIOS_USER=${NAGIOS_USER}
MESSAGE_SUBST+=		NAGIOSCMD_GROUP=${NAGIOSCMD_GROUP}

EGDIR=			${PREFIX}/share/examples/nagios
EGFILES=		nagios.cfg cgi.cfg resource.cfg
EGFILES+=		objects/templates.cfg objects/commands.cfg
EGFILES+=		objects/contacts.cfg objects/timeperiods.cfg
EGFILES+=		objects/localhost.cfg objects/windows.cfg
EGFILES+=		objects/printer.cfg objects/switch.cfg

INSTALLATION_DIRS+=	${PKG_SYSCONFDIR}/objects

.for files in ${EGFILES}
CONF_FILES+=		${EGDIR}/${files}-sample ${PKG_SYSCONFDIR}/${files}
.endfor
CONF_FILES+=		${EGDIR}/nagios.conf ${PKG_SYSCONFDIR}/nagios.conf

OWN_DIRS_PERMS+=${NAGIOSDIR} ${NAGIOS_USER} ${NAGIOS_GROUP} 0775
OWN_DIRS_PERMS+=${NAGIOSDIR}/archives ${NAGIOS_USER} ${NAGIOS_GROUP} 0775
OWN_DIRS_PERMS+=${NAGIOSDIR}/rw ${NAGIOS_USER} ${NAGIOSCMD_GROUP} 0775
OWN_DIRS_PERMS+=${NAGIOSDIR}/checkresults ${NAGIOS_USER} ${NAGIOSCMD_GROUP} 0775

SPECIAL_PERMS+=	${DESTDIR}/${PREFIX}/share/nagios/jsonquery.html ${NAGIOS_USER} ${NAGIOSCMD_GROUP} 0644
SPECIAL_PERMS+=	${DESTDIR}/${PREFIX}/share/nagios/rss-newsfeed.html ${NAGIOS_USER} ${NAGIOSCMD_GROUP} 0644

SUBST_CLASSES+=		files
SUBST_STAGE.files=	post-build
SUBST_FILES.files=	nagios.conf.dist
SUBST_SED.files=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_MESSAGE.files=	Fixing configuration files.

pre-build:
	${CP} ${FILESDIR}/nagios.conf.dist ${WRKSRC}/nagios.conf.dist

post-install:
	${INSTALL_DATA} ${WRKSRC}/nagios.conf.dist ${DESTDIR}/${EGDIR}/nagios.conf
	${INSTALL_DATA} ${WRKDIR}/netbsd40.gd2 \
	    ${DESTDIR}/${PREFIX}/share/nagios/images/logos/
	${INSTALL_DATA} ${WRKDIR}/netbsd40.gif \
	    ${DESTDIR}/${PREFIX}/share/nagios/images/logos/
	${INSTALL_DATA} ${WRKDIR}/netbsd40.jpg \
	    ${DESTDIR}/${PREFIX}/share/nagios/images/logos/
	${INSTALL_DATA} ${WRKDIR}/netbsd40.png \
	    ${DESTDIR}/${PREFIX}/share/nagios/images/logos/
	${CHMOD} g-w ${DESTDIR}${PREFIX}/share/nagios/jsonquery.html

.include "../../mk/dlopen.buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
