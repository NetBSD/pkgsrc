# $NetBSD: Makefile,v 1.3 2006/05/26 18:53:25 wiz Exp $
#

DISTNAME=		nrpe-2.5.1
PKGNAME=		nagios-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		net sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=nagios/}

MAINTAINER=     	pkgsrc-users@NetBSD.org
HOMEPAGE=       	http://sourceforge.net/projects/nagios/
COMMENT=		Nagios remote program execution daemon

GNU_CONFIGURE=		yes
USE_TOOLS+=		perl
USE_PKGINSTALL=		yes

PKG_SYSCONFSUBDIR=	nagios
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec/nagios
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

NAGIOS_USER?=		nagios
NAGIOS_GROUP?=		${NAGIOS_USER}

PKG_GROUPS+=		${NAGIOS_GROUP}
PKG_USERS+=		${NAGIOS_USER}:${NAGIOS_GROUP}::Nagios\ Runtime\ User

CONFIGURE_ARGS+=	--with-nrpe-user=${NAGIOS_USER:Q}
CONFIGURE_ARGS+=	--with-nrpe-group=${NAGIOS_GROUP:Q}

CONF_FILES+=		${PREFIX}/share/examples/nagios/nrpe.cfg ${PKG_SYSCONFDIR}/nrpe.cfg
RCD_SCRIPTS+=		nrpe

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nrpe ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/nagios
	${INSTALL_PROGRAM} ${WRKSRC}/src/check_nrpe ${PREFIX}/libexec/nagios
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/nagios
	${INSTALL_DATA} ${WRKSRC}/sample-config/nrpe.cfg ${PREFIX}/share/examples/nagios
	${INSTALL_SCRIPT} ${WRKDIR}/nrpe ${PREFIX}/${RCD_SCRIPTS_EXAMPLEDIR}

.include "../../mk/bsd.pkg.mk"
