# $NetBSD: Makefile,v 1.26 2019/08/11 13:21:24 wiz Exp $

DISTNAME=	amavisd-new-${VERSION}${PATCHLEVEL}
PKGNAME=	amavisd-new-${VERSION}${PATCHLEVEL:S/-//}
PKGREVISION=	1
CATEGORIES=	mail security
MASTER_SITES=	https://www.ijs.si/software/amavisd/
MASTER_SITES+=	http://mirrors.catpipe.net/amavisd-new/
MASTER_SITES+=	http://mirror.mainloop.se/amavisd/
MASTER_SITES+=	http://mirror.cedratnet.com/amavisd-new/
MASTER_SITES+=	http://mirror.omroep.nl/amavisd-new/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	spz@NetBSD.org
HOMEPAGE=	https://www.ijs.si/software/amavisd/
COMMENT=	Daemonized interface between MTA and content checkers
LICENSE=	gnu-gpl-v2

VERSION=	2.11.1
PATCHLEVEL=	# empty

DEPENDS+=	p5-Archive-Zip>=1.14:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-BerkeleyDB-[0-9]*:../../databases/p5-BerkeleyDB
DEPENDS+=	p5-Convert-TNEF-[0-9]*:../../converters/p5-Convert-TNEF
DEPENDS+=	p5-Convert-UUlib>=1.05:../../converters/p5-Convert-UUlib
DEPENDS+=	p5-File-LibMagic>=1.0:../../devel/p5-File-LibMagic
DEPENDS+=	p5-Mail-DKIM>=0.31:../../mail/p5-Mail-DKIM
DEPENDS+=	p5-MIME-tools>=5.417:../../mail/p5-MIME-tools
DEPENDS+=	p5-MailTools>=1.58:../../mail/p5-MailTools
DEPENDS+=	p5-Net-LibIDN-[0-9]*:../../net/p5-Net-LibIDN
DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
DEPENDS+=	p5-Net-Server>=0.88:../../net/p5-Net-Server
DEPENDS+=	p5-Unix-Syslog-[0-9]*:../../sysutils/p5-Unix-Syslog

WRKSRC=		${WRKDIR}/amavisd-new-${VERSION}

CONFLICTS+=	amavis-[0-9]*
CONFLICTS+=	amavis-perl-[0-9]*

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		perl:run
REPLACE_PERL+=		amavisd amavisd-nanny amavisd-release amavisd-agent

AMAVIS_USER?=		vscan
AMAVIS_GROUP?=		vscan
AMAVIS_DIR?=		${VARBASE}/amavis
AMAVIS_QUARANTINE?=	${VARBASE}/virusmails
DOCDIR=			${PREFIX}/share/doc/amavisd-new
EGDIR=			${PREFIX}/share/examples/amavisd-new
MESSAGE_SRC=		${PKGDIR}/MESSAGE

PKG_GROUPS_VARS+=	AMAVIS_GROUP
PKG_USERS_VARS+=	AMAVIS_USER
BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		AMAVIS_DIR AMAVIS_QUARANTINE
FILES_SUBST+=		AMAVIS_USER=${AMAVIS_USER}
FILES_SUBST+=		AMAVIS_GROUP=${AMAVIS_GROUP}
FILES_SUBST+=		AMAVIS_DIR=${AMAVIS_DIR}
FILES_SUBST+=		AMAVIS_QUARANTINE=${AMAVIS_QUARANTINE:Q}

PKG_GROUPS=	${AMAVIS_GROUP}
PKG_USERS=	${AMAVIS_USER}:${AMAVIS_GROUP}

PKG_GECOS.${AMAVIS_USER}=	AMaViS Virus Scanning Account
PKG_HOME.${AMAVIS_USER}=	${AMAVIS_DIR}
PKG_SHELL.${AMAVIS_USER}=	${SH}

OWN_DIRS+=			${AMAVIS_DIR} ${AMAVIS_DIR}/db ${AMAVIS_DIR}/tmp
OWN_DIRS+=			${AMAVIS_QUARANTINE}
OWN_DIRS_PERMS+=		${AMAVIS_DIR} ${AMAVIS_USER} ${AMAVIS_GROUP} 750
OWN_DIRS_PERMS+=		${AMAVIS_DIR}/db ${AMAVIS_USER} ${AMAVIS_GROUP} 750
OWN_DIRS_PERMS+=		${AMAVIS_DIR}/tmp ${AMAVIS_USER} ${AMAVIS_GROUP} 750
OWN_DIRS_PERMS+=		${AMAVIS_QUARANTINE} ${AMAVIS_USER} ${AMAVIS_GROUP} 750

RCD_SCRIPTS=	amavisd
SMF_NAME=	amavisd
CONF_FILES=	${EGDIR}/amavisd.conf-minimal ${PKG_SYSCONFDIR}/amavisd.conf

USE_LANGUAGES=		# none, not even C

do-build:	replace-interpreter

SUBST_CLASSES+=		amavisd
SUBST_STAGE.amavisd=	pre-build
SUBST_FILES.amavisd=	amavisd amavisd.conf
SUBST_SED.amavisd=	-e "s|/etc/amavisd.conf|${PKG_SYSCONFDIR}/amavisd.conf|"
SUBST_VARS.amavisd=	AMAVIS_DIR
SUBST_VARS.amavisd+=	AMAVIS_USER
SUBST_VARS.amavisd+=	AMAVIS_GROUP
SUBST_VARS.amavisd+=	AMAVIS_QUARANTINE
SUBST_VARS.amavisd+=	LOCALBASE
SUBST_VARS.amavisd+=	PREFIX

INSTALLATION_DIRS+=	sbin ${DOCDIR} ${EGDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/amavisd ${DESTDIR}${PREFIX}/sbin/amavisd
	${INSTALL_SCRIPT} ${WRKSRC}/amavisd-nanny ${DESTDIR}${PREFIX}/sbin/amavisd-nanny
	${INSTALL_SCRIPT} ${WRKSRC}/amavisd-release ${DESTDIR}${PREFIX}/sbin/amavisd-release
	${INSTALL_SCRIPT} ${WRKSRC}/amavisd-agent ${DESTDIR}${PREFIX}/sbin/amavisd-agent
	${INSTALL_DATA} ${WRKSRC}/AAAREADME.first ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LDAP.schema ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/MANIFEST ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README_FILES/amavisd-new-docs.html ${DESTDIR}${DOCDIR}
	for file in README_FILES/README.*; do				\
		${INSTALL_DATA} ${WRKSRC}/$$file ${DESTDIR}${DOCDIR};	\
	done
	${INSTALL_DATA} ${WRKSRC}/amavisd.conf ${DESTDIR}${EGDIR}/amavisd.conf-minimal
	${INSTALL_DATA} ${WRKSRC}/amavisd.conf-default ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
