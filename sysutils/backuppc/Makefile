# $NetBSD: Makefile,v 1.20 2023/07/03 13:08:12 wiz Exp $

DISTNAME=	BackupPC-4.4.0
PKGREVISION=	4
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=backuppc/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	https://backuppc.github.io/backuppc/
COMMENT=	Fast, agentless backup system supporting *NIX, Windows and OSX clients
LICENSE=	gnu-gpl-v3

RSYNC_BPC=	rsync-bpc-3.1.2.2
RSYNC_BPC_TGZ=	${RSYNC_BPC}.tar.gz
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	${RSYNC_BPC_TGZ}
SITES.${RSYNC_BPC_TGZ}=	${MASTER_SITE_GITHUB:=backuppc/}rsync-bpc/releases/download/${RSYNC_BPC:S/rsync-bpc-//}/

DEPENDS+=	rsync-[0-9]*:../../net/rsync
DEPENDS+=	samba<4:../../net/samba
DEPENDS+=	par2-[0-9]*:../../archivers/par2
#DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI
DEPENDS+=	p5-File-Listing-[0-9]*:../../devel/p5-File-Listing
DEPENDS+=	p5-BackupPC-XS>=0.62:../../sysutils/p5-BackupPC-XS

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	bzip2:run cat:run tar:run perl:run hostname:run gzip:run pax

OVERRIDE_GNU_CONFIG_SCRIPTS=	yes
CONFIG_GUESS_OVERRIDE=		../${RSYNC_BPC}/config.guess
CONFIG_SUB_OVERRIDE=		../${RSYNC_BPC}/config.sub
BUILD_DIRS=			../${RSYNC_BPC}

CONFIG_SHELL=		${PERL5}
CONFIGURE_SCRIPT=	configure.pl
CONFIGURE_ARGS+=	--batch
CONFIGURE_ARGS+=	--backuppc-user ${BACKUPPC_USER}
CONFIGURE_ARGS+=	--hostname localhost
CONFIGURE_ARGS+=	--dest-dir ${WRKSRC}/build
CONFIGURE_ARGS+=	--config-dir ${PREFIX}/share/examples/BackupPC
CONFIGURE_ARGS+=	--cgi-dir ${PREFIX}/share/BackupPC/cgi-bin
CONFIGURE_ARGS+=	--data-dir ${VARBASE}/BackupPC
CONFIGURE_ARGS+=	--html-dir ${PREFIX}/share/BackupPC/htdocs
CONFIGURE_ARGS+=	--html-dir-url /BackupPC
CONFIGURE_ARGS+=	--install-dir ${PREFIX}/share/BackupPC
CONFIGURE_ARGS+=	--log-dir ${VARBASE}/log/BackupPC
CONFIGURE_ARGS+=	--uid-ignore
CONFIGURE_ARGS+=	--no-set-perms

CONFIGURE_ARGS+=	--bin-path bzip2=${TOOLS_PATH.bzip2}
CONFIGURE_ARGS+=	--bin-path cat=${TOOLS_PATH.cat}
CONFIGURE_ARGS+=	--bin-path tar=${TOOLS_PATH.tar}
CONFIGURE_ARGS+=	--bin-path gzip=${TOOLS_PATH.gzip}
CONFIGURE_ARGS+=	--bin-path hostname=${TOOLS_PATH.hostname}

CONFIGURE_ARGS+=	--bin-path perl=${PERL5}
CONFIGURE_ARGS+=	--bin-path rsync=${PREFIX}/bin/rsync
CONFIGURE_ARGS+=	--bin-path nmblookup=${PREFIX}/bin/nmblookup
CONFIGURE_ARGS+=	--bin-path smbclient=${PREFIX}/bin/smbclient
CONFIGURE_ARGS+=	--bin-path par2=${PREFIX}/bin/par2
CONFIGURE_ARGS+=	--bin-path rsync_bpc=${PREFIX}/bin/rsync_bpc

.if exists(/usr/bin/ssh)
CONFIGURE_ARGS+=	--bin-path ssh=/usr/bin/ssh
.else
DEPENDS+=		openssh-[0-9]*:../../security/openssh
CONFIGURE_ARGS+=	--bin-path ssh=${PREFIX}/bin/ssh
.endif

BUILD_DEFS+=		BACKUPPC_USER BACKUPPC_GROUP APACHE_USER APACHE_GROUP VARBASE

BACKUPPC_USER?=		backuppc
BACKUPPC_GROUP?=	backuppc

PKG_USERS_VARS=		BACKUPPC_USER
PKG_GROUPS_VARS=	BACKUPPC_GROUP
PKG_GROUPS=		${BACKUPPC_GROUP}
PKG_USERS=		${BACKUPPC_USER}:${BACKUPPC_GROUP}

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		post-configure
SUBST_MESSAGE.fix-paths=	Substituting paths and usernames.
SUBST_FILES.fix-paths=		${WRKSRC}/build/${PREFIX}/share/examples/BackupPC/config.pl
SUBST_FILES.fix-paths+=		${WRKSRC}/build/${PREFIX}/share/BackupPC/share/doc/BackupPC/*
SUBST_FILES.fix-paths+=		${WRKSRC}/build/${PREFIX}/share/BackupPC/lib/BackupPC/Lib.pm
SUBST_FILES.fix-paths+=		${WRKSRC}/backuppc.conf
SUBST_FILES.fix-paths+=		${WRKSRC}/cgiwrapper.c
SUBST_SED.fix-paths=		-e 's,${PREFIX}/share/examples/BackupPC,${PKG_SYSCONFDIR},g'
SUBST_VARS.fix-paths=		PREFIX
SUBST_VARS.fix-paths+=		PKG_SYSCONFDIR
SUBST_VARS.fix-paths+=		APACHE_USER
SUBST_VARS.fix-paths+=		APACHE_GROUP
SUBST_VARS.fix-paths+=		BACKUPPC_USER
SUBST_VARS.fix-paths+=		BACKUPPC_GROUP
SUBST_VARS.fix-paths+=		PERL5

FILES_SUBST+=			BACKUPPC_USER=${BACKUPPC_USER:Q} BACKUPPC_GROUP=${BACKUPPC_GROUP:Q}

PKG_SYSCONFSUBDIR=	BackupPC
PKG_SYSCONFDIR_PERMS=	${BACKUPPC_USER} ${BACKUPPC_GROUP} 0755
RCD_SCRIPTS=		backuppc

OWN_DIRS_PERMS+=	${VARBASE}/BackupPC ${BACKUPPC_USER} ${BACKUPPC_GROUP} 0750
.for d in pool cpool pc trash
OWN_DIRS_PERMS+=	${VARBASE}/BackupPC/${d} ${BACKUPPC_USER} ${BACKUPPC_GROUP} 0750
.endfor
OWN_DIRS_PERMS+=	${VARBASE}/log/BackupPC ${BACKUPPC_USER} ${BACKUPPC_GROUP} 0750

EGDIR=			${PREFIX}/share/examples/BackupPC
CONF_FILES_PERMS+=	${EGDIR}/config.pl ${PKG_SYSCONFDIR}/config.pl ${BACKUPPC_USER} ${BACKUPPC_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/hosts ${PKG_SYSCONFDIR}/hosts ${BACKUPPC_USER} ${BACKUPPC_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/backuppc.conf ${PKG_SYSCONFDIR}/backuppc.conf ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0644

post-extract:
	cp ${FILESDIR}/backuppc.conf ${WRKSRC}/backuppc.conf
	cp ${FILESDIR}/cgiwrapper.c ${WRKSRC}/cgiwrapper.c

post-configure:
	cd ${WRKDIR}/${RSYNC_BPC} && ${SETENV} ${CONFIGURE_ENV} ${SH} ./configure --prefix=${PREFIX} --with-included-popt

post-build:
	rm -rf ${WRKSRC}/build/${VARBASE}

post-install:
	cd ${WRKSRC}/build && pax -rw . ${DESTDIR}/
	chmod +x ${DESTDIR}${PREFIX}/share/BackupPC/bin/*
	${INSTALL_DATA} ${WRKSRC}/backuppc.conf ${DESTDIR}${PREFIX}/share/examples/BackupPC/backuppc.conf
	${INSTALL_DATA} ${WRKSRC}/cgiwrapper.c ${DESTDIR}${PREFIX}/share/examples/BackupPC/cgiwrapper.c

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
