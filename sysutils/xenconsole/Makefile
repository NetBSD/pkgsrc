# $NetBSD: Makefile,v 1.1.1.1 2005/11/13 18:36:00 martti Exp $

DISTNAME=	xenConsole-r0.15b1-1
PKGNAME=	xenconsole-0.15b1.1
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

SUBST_CLASSES+=			xenconsole
SUBST_STAGE.xenconsole=		pre-configure
SUBST_MESSAGE.xenconsole=	"Fixing paths."
SUBST_FILES.xenconsole=		xcon.pl xen_list.pm
SUBST_SED.xenconsole=		-e "s,@PREFIX@,${PREFIX},g"
SUBST_SED.xenconsole+=		-e "s,@LOCALBASE@,${LOCALBASE},g"

REPLACE_PERL=		xcon.pl xsnmp.pm

USE_PKGINSTALL=		yes
EGDIR=			${PREFIX}/share/examples/xenconsole
CONF_FILES=		${EGDIR}/xcon.ini ${PKG_SYSCONFDIR}/xcon.ini

do-build:
	${SED} -e "s,@PREFIX@,${PREFIX},g" \
		< ${FILESDIR}/xcon.sh > ${WRKDIR}/xcon

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xenconsole
	(cd ${WRKSRC} && ${PAX} -rw *.pm */*.pm ${PREFIX}/share/xenconsole)
	${INSTALL_SCRIPT} ${WRKSRC}/xcon.pl ${PREFIX}/share/xenconsole/xcon

	# Configuration file
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sample-inifile ${EGDIR}/xcon.ini

	# Documentation
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xenconsole
	(cd ${WRKSRC} && ${PAX} -rw *.txt ${PREFIX}/share/doc/xenconsole)

	# Launcher script
	${INSTALL_SCRIPT} ${WRKDIR}/xcon ${PREFIX}/bin/xcon

.include "../../mk/bsd.pkg.mk"
