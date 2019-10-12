# $NetBSD: Makefile,v 1.14 2019/10/12 20:53:48 rillig Exp $
#

DISTNAME=		snmptt_1.3
PKGNAME=		snmptt-1.3
PKGREVISION=		11
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=snmptt/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		bouyer@NetBSD.org
HOMEPAGE=		http://www.snmptt.org/
COMMENT=		SNMP trap handler written in Perl

DEPENDS+=		p5-Config-IniFiles-[0-9]*:../../devel/p5-Config-IniFiles
#DEPENDS+=		{perl>=5.7.3,p5-Time-HiRes-[0-9]*}:../../time/p5-Time-HiRes
DEPENDS+=		p5-Text-Balanced-[0-9]*:../../textproc/p5-Text-Balanced
DEPENDS+=		p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=		p5-DBD-ODBC-[0-9]*:../../databases/p5-DBD-ODBC
#DEPENDS+=		{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5

WRKSRC=			${WRKDIR}/${DISTNAME}

PKG_SYSCONFSUBDIR=	snmptt

INSTALLATION_DIRS+=	sbin

RCD_SCRIPTS=		snmptt

BUILD_DEFS+=	VARBASE
.include "../../mk/bsd.prefs.mk"

EGDIR=		${PREFIX}/share/examples/snmptt
CONF_FILES=	${EGDIR}/snmptt.ini ${PKG_SYSCONFDIR}/snmptt.ini

DOCDIR=		${PREFIX}/share/doc/snmptt

MAKE_DIRS_PERMS+=	${VARBASE}/spool/snmptt ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0755

USE_TOOLS+=	perl:run
REPLACE_PERL+=	snmptt
REPLACE_PERL+=	snmptt-net-snmp-test
REPLACE_PERL+=	snmpttconvert
REPLACE_PERL+=	snmptthandler
REPLACE_PERL+=	snmptthandler-embedded
REPLACE_PERL+=	snmpttconvertmib

SUBST_CLASSES+=			installdir
SUBST_STAGE.installdir=		pre-configure
SUBST_FILES.installdir=		snmptt
SUBST_FILES.installdir+=	snmptthandler
SUBST_FILES.installdir+=	snmptthandler-embedded
SUBST_SED.installdir=		-e "s|/sbin|${PREFIX}/sbin|g"
SUBST_MESSAGE.installdir=	Fixing hardcoded install directory path.

SUBST_CLASSES+=		etcdir
SUBST_STAGE.etcdir=	pre-configure
SUBST_FILES.etcdir=	snmptt
SUBST_FILES.etcdir+=	snmptt.ini
SUBST_FILES.etcdir+=	snmptthandler
SUBST_FILES.etcdir+=	docs/faqs.html
SUBST_FILES.etcdir+=	docs/snmptt.html
SUBST_FILES.etcdir+=	docs/snmpttconvertmib.html
SUBST_FILES.etcdir+=	snmptthandler-embedded
SUBST_SED.etcdir=	-e "s|/etc|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.etcdir=	Fixing hardcoded /etc path.

SUBST_CLASSES+=		vardir
SUBST_STAGE.vardir=	pre-configure
SUBST_FILES.vardir=	snmptt snmptt.ini
SUBST_SED.vardir=	-e "s|/var|${VARBASE}|g"
SUBST_MESSAGE.vardir=	Fixing hardcoded /var path.

SUBST_CLASSES+=		log
SUBST_STAGE.log=	pre-configure
SUBST_FILES.log=	snmptt.ini
SUBST_SED.log=		-e "s|/log/snmptt/|/log/|g"
SUBST_MESSAGE.log=	move ${VARBASE}/log/snmptt/ to ${VARBASE}/log

do-build:

do-install:
	for i in snmptt snmptt-net-snmp-test snmpttconvert \
	     snmptthandler snmptthandler-embedded snmpttconvertmib; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/sbin/; \
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	for i in snmptt.ini; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${EGDIR}/; \
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	for i in docs/*; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${DOCDIR}/; \
	done

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
