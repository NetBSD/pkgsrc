# $NetBSD: Makefile,v 1.4 2022/06/28 11:35:03 wiz Exp $

DISTNAME=	check_printer
REVISION=	363
PKGREVISION=	3
PKGNAME=	nagios-plugin-printer-0.0.${REVISION}
CATEGORIES=	net sysutils
# Can this be converted to GITHUB_*?
MASTER_SITES=	${MASTER_SITE_GITHUB:=bzed/pkg-nagios-plugins-contrib/raw/debian/25.20191015+1/check_printer/}
EXTRACT_SUFX=	# empty
DIST_SUBDIR=	check_printer-${REVISION}

COMMENT=	Gather supply metrics from a printer via SNMP query
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# empty
USE_TOOLS+=	perl:run

DEPENDS+=	net-snmp-[0-9]*:../../net/net-snmp

WRKSRC=		${WRKDIR}

PLUGINDIR=		libexec/nagios
PLIST_SUBST+=		PLUGINDIR=${PLUGINDIR}

INSTALLATION_DIRS+=	${PLUGINDIR}

REPLACE_PERL+=		check_printer

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing paths
SUBST_FILES.paths=	check_printer
SUBST_SED.paths=	-e 's;@LIBDIR@;${PREFIX}/${PLUGINDIR};'
SUBST_VARS.paths=	PREFIX

NO_BUILD=	yes

do-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/check_printer ${DESTDIR}${PREFIX}/${PLUGINDIR}

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
