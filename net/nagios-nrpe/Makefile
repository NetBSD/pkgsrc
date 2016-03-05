# $NetBSD: Makefile,v 1.29 2016/03/05 11:29:08 jperkin Exp $
#

DISTNAME=		nrpe-2.15
PKGNAME=		nagios-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		net sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=nagios/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nagios.org/
COMMENT=		Nagios remote program execution daemon

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes
USE_TOOLS+=		perl

PKG_SYSCONFSUBDIR=	nagios
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec/nagios
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

PKG_GROUPS+=			${NAGIOS_GROUP}
PKG_USERS+=			${NAGIOS_USER}:${NAGIOS_GROUP}
PKG_GECOS.${NAGIOS_USER}=	Nagios Runtime User

PKG_GROUPS_VARS+=	NAGIOS_GROUP
PKG_USERS_VARS+=	NAGIOS_USER

CONFIGURE_ARGS+=	--with-nrpe-user=${NAGIOS_USER:Q}
CONFIGURE_ARGS+=	--with-nrpe-group=${NAGIOS_GROUP:Q}
CONFIGURE_ARGS+=	--with-nagios-user=${NAGIOS_USER:Q}
CONFIGURE_ARGS+=	--with-nagios-group=${NAGIOS_GROUP:Q}

CONF_FILES+=		${PREFIX}/share/examples/nagios/nrpe.cfg ${PKG_SYSCONFDIR}/nrpe.cfg
RCD_SCRIPTS+=		nrpe
SMF_NAME=		nrpe
FILES_SUBST+=		NAGIOS_USER=${NAGIOS_USER}
FILES_SUBST+=		NAGIOS_GROUP=${NAGIOS_GROUP}
FILES_SUBST+=		NAGIOSDIR=${NAGIOSDIR}

INSTALLATION_DIRS+=	sbin libexec/nagios share/examples/nagios

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nrpe ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/src/check_nrpe ${DESTDIR}${PREFIX}/libexec/nagios
	${INSTALL_DATA} ${WRKSRC}/sample-config/nrpe.cfg ${DESTDIR}${PREFIX}/share/examples/nagios

.include "../../mk/bsd.pkg.mk"
