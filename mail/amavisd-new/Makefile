# $NetBSD: Makefile,v 1.11 2013/12/09 14:17:48 obache Exp $

DISTNAME=	amavisd-new-${VERSION}${PATCHLEVEL}
PKGNAME=	amavisd-new-${VERSION}${PATCHLEVEL:S/-//}
PKGREVISION=	4
CATEGORIES=	mail security
MASTER_SITES=	http://www.ijs.si/software/amavisd/ \
		http://mirrors.catpipe.net/amavisd-new/ \
		http://mirror.mainloop.se/amavisd/ \
		http://mirror.cedratnet.com/amavisd-new/ \
		http://mirror.omroep.nl/amavisd-new/

MAINTAINER=	spz@NetBSD.org
HOMEPAGE=	http://www.ijs.si/software/amavisd/
COMMENT=	Daemonized interface between MTA and content checkers
LICENSE=	gnu-gpl-v2

VERSION=	2.7.0
PATCHLEVEL=	# empty

DEPENDS+=	{perl>=5.9.3,p5-Archive-Tar-[0-9]*}:../../archivers/p5-Archive-Tar
DEPENDS+=	p5-Archive-Zip>=1.14:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-BerkeleyDB-[0-9]*:../../databases/p5-BerkeleyDB
DEPENDS+=	{perl>=5.10.1,p5-IO-Compress>=2.017}:../../devel/p5-IO-Compress	# Compress::Raw::Zlib>=2.017
DEPENDS+=	p5-Convert-TNEF-[0-9]*:../../converters/p5-Convert-TNEF
DEPENDS+=	p5-Convert-UUlib>=1.05:../../converters/p5-Convert-UUlib
DEPENDS+=	{perl>=5.8.1,p5-Digest-MD5>=2.22}:../../security/p5-Digest-MD5
DEPENDS+=	p5-Mail-DKIM>=0.31:../../mail/p5-Mail-DKIM
DEPENDS+=	p5-MIME-tools>=5.417:../../mail/p5-MIME-tools
DEPENDS+=	p5-MailTools>=1.58:../../mail/p5-MailTools
DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
DEPENDS+=	p5-Net-Server>=0.88:../../net/p5-Net-Server
DEPENDS+=	{perl>=5.8.1,p5-Time-HiRes>=1.49}:../../time/p5-Time-HiRes
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
CONF_FILES=	${EGDIR}/amavisd.conf-minimal ${PKG_SYSCONFDIR}/amavisd.conf

PKG_OPTIONS_VAR=	PKG_OPTIONS.amavisd-new
PKG_SUPPORTED_OPTIONS=	milter

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		milter
.if !empty(PKG_OPTIONS:Mmilter)
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-runtime-dir=${AMAVIS_DIR}
CONFIGURE_ARGS+=	--with-sockname=${AMAVIS_DIR}/amavisd.sock
CONFIGURE_ARGS+=	--with-user=${AMAVIS_USER}
CONFIGURE_ARGS+=	--with-milterinc=${BUILDLINK_PREFIX.libmilter}/include
CONFIGURE_ARGS+=	--with-milterlib=${BUILDLINK_PREFIX.libmilter}/lib
CONFIGURE_DIRS=		helper-progs
BUILD_DIRS=		helper-progs
RCD_SCRIPTS+=		amavismilter
MESSAGE_SRC+=		${PKGDIR}/MESSAGE.milter
PLIST.milter=		yes

PTHREAD_OPTS+=		require native	# doesn't work with pth
.  include "../../mail/libmilter/buildlink3.mk"
.  include "../../mk/pthread.buildlink3.mk"
.else
USE_LANGUAGES=		# none, not even C

do-build:	replace-interpreter
.endif

SUBST_CLASSES+=		amavisd
SUBST_STAGE.amavisd=	pre-build
SUBST_FILES.amavisd=	amavisd amavisd.conf
SUBST_SED.amavisd=	-e "s|/etc/amavisd.conf|${PKG_SYSCONFDIR}/amavisd.conf|"
SUBST_SED.amavisd+=	-e "s|@AMAVIS_DIR@|${AMAVIS_DIR}|g"
SUBST_SED.amavisd+=	-e "s|@AMAVIS_USER@|${AMAVIS_USER}|g"
SUBST_SED.amavisd+=	-e "s|@AMAVIS_GROUP@|${AMAVIS_GROUP}|g"
SUBST_SED.amavisd+=	-e "s|@AMAVIS_QUARANTINE@|${AMAVIS_QUARANTINE}|g"
SUBST_SED.amavisd+=	-e "s|@LOCALBASE@|${LOCALBASE}|g"
SUBST_SED.amavisd+=	-e "s|@PREFIX@|${PREFIX}|g"

INSTALLATION_DIRS=	sbin ${DOCDIR} ${EGDIR}

do-install:
.if !empty(PKG_OPTIONS:Mmilter)
	${INSTALL_PROGRAM} ${WRKSRC}/helper-progs/amavis ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/helper-progs/amavis-milter ${DESTDIR}${PREFIX}/sbin
.endif
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
