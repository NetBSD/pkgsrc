# $NetBSD: Makefile,v 1.5 2006/07/09 22:36:28 rillig Exp $

DISTNAME=	xenConsole-r0.15b1-1
PKGNAME=	xenconsole-0.15b1.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ucck/}

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://ucck.sourceforge.net/xenConsole/
COMMENT=	Console monitor for Xen

WRKSRC=		${WRKDIR}/xenConsole

DEPENDS+=	p5-Config-IniFiles>=2.38:../../devel/p5-Config-IniFiles
DEPENDS+=	p5-Curses-UI>=0.95:../../devel/p5-Curses-UI
DEPENDS+=	p5-Curses-UI-POE>=0.02801:../../devel/p5-Curses-UI-POE
DEPENDS+=	p5-Data-Table>=1.43:../../databases/p5-Data-Table
DEPENDS+=	p5-Net-SNMP>=5.0.1:../../net/p5-Net-SNMP
DEPENDS+=	p5-POE>=0.3101:../../devel/p5-POE
DEPENDS+=	p5-POE-Component-SNMP>=0.93:../../net/p5-POE-Component-SNMP
DEPENDS+=	p5-Sys-CpuLoad>=0.03:../../sysutils/p5-Sys-CpuLoad
DEPENDS+=	p5-Term-Size>=0.2:../../devel/p5-Term-Size
DEPENDS+=	p5-Time-HiRes>=0:../../time/p5-Time-HiRes

USE_TOOLS+=	perl:run

SUBST_CLASSES+=			xenconsole
SUBST_STAGE.xenconsole=		pre-configure
SUBST_MESSAGE.xenconsole=	Fixing paths.
SUBST_FILES.xenconsole=		xcon.pl xen_list.pm
SUBST_SED.xenconsole=		-e s,@PREFIX@,${PREFIX:Q},g
SUBST_SED.xenconsole+=		-e s,@LOCALBASE@,${LOCALBASE:Q},g

REPLACE_PERL+=		xcon.pl xsnmp.pm

EGDIR=			${PREFIX}/share/examples/xenconsole
CONF_FILES=		${EGDIR:Q}/xcon.ini ${PKG_SYSCONFDIR:Q}/xcon.ini

do-build:
	${SED} -e "s,@PREFIX@,${PREFIX:Q},g" \
		< ${FILESDIR:Q}/xcon.sh > ${WRKDIR:Q}/xcon

do-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/xenconsole
	(cd ${WRKSRC:Q} && ${PAX} -rw *.pm */*.pm ${PREFIX:Q}/share/xenconsole)
	${INSTALL_SCRIPT} ${WRKSRC:Q}/xcon.pl ${PREFIX:Q}/share/xenconsole/xcon

	# Configuration file
	${INSTALL_DATA_DIR} ${EGDIR:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/sample-inifile ${EGDIR:Q}/xcon.ini

	# Documentation
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/doc/xenconsole
	(cd ${WRKSRC:Q} && ${PAX} -rw *.txt ${PREFIX:Q}/share/doc/xenconsole)

	# Launcher script
	${INSTALL_SCRIPT} ${WRKDIR:Q}/xcon ${PREFIX:Q}/bin/xcon

.include "../../mk/bsd.pkg.mk"
