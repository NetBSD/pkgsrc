# $NetBSD: Makefile,v 1.3 2022/06/28 11:35:03 wiz Exp $

DISTNAME=	check_snmp_environment.pl
VERSION=	0.7
PKGREVISION=	3
PKGNAME=	nagios-plugin-snmp_environment-${VERSION}
CATEGORIES=	net sysutils
MASTER_SITES=	-https://exchange.nagios.org/components/com_mtree/attachment.php?link_id=483&cf_id=24
EXTRACT_SUFX=	# empty
DIST_SUBDIR=	check_snmp_environment-${VERSION}

COMMENT=	Check various hardware environmental sensors
HOMEPAGE=	https://exchange.nagios.org/directory/Plugins/Hardware/Network-Gear/Cisco/Check-various-hardware-environmental-sensors/details
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# empty
USE_TOOLS+=	perl:run

DEPENDS+=	net-snmp-[0-9]*:../../net/net-snmp

WRKSRC=		${WRKDIR}

do-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}

PLUGINDIR=		libexec/nagios
PLIST_SUBST+=		PLUGINDIR=${PLUGINDIR}

INSTALLATION_DIRS+=	${PLUGINDIR}

REPLACE_PERL+=		check_snmp_environment.pl

NO_BUILD=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/check_snmp_environment.pl ${DESTDIR}${PREFIX}/${PLUGINDIR}/check_snmp_environment

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
