# $NetBSD: Makefile,v 1.4 2016/02/27 21:25:01 tnn Exp $

DISTNAME=	BackupPC-3.3.1
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=backuppc/}

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://backuppc.sourceforge.net/
COMMENT=	Fast, agentless backup system supporting *NIX, Windows and OSX clients
LICENSE=	gnu-gpl-v2

DEPENDS+=	rsync-[0-9]*:../../net/rsync
DEPENDS+=	samba-[0-9]*:../../net/samba
DEPENDS+=	par2-[0-9]*:../../archivers/par2
DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI
DEPENDS+=	p5-File-Listing-[0-9]*:../../devel/p5-File-Listing
DEPENDS+=	p5-File-RsyncP-[0-9]*:../../net/p5-File-RsyncP

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	bzip2:run cat:run tar:run perl:run hostname:run gzip:run pax

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
SUBST_FILES.fix-paths+=		${WRKSRC}/build/${PREFIX}/share/BackupPC/doc/*
SUBST_FILES.fix-paths+=		${WRKSRC}/build/${PREFIX}/share/BackupPC/lib/BackupPC/Lib.pm
SUBST_FILES.fix-paths+=		${WRKSRC}/backuppc.conf
SUBST_FILES.fix-paths+=		${WRKSRC}/cgiwrapper.c
SUBST_SED.fix-paths=		-e 's,${PREFIX}/share/examples/BackupPC,${PKG_SYSCONFDIR},g'
SUBST_SED.fix-paths+=		-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.fix-paths+=		-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.fix-paths+=		-e 's,@APACHE_USER@,${APACHE_USER},g'
SUBST_SED.fix-paths+=		-e 's,@APACHE_GROUP@,${APACHE_GROUP},g'
SUBST_SED.fix-paths+=		-e 's,@BACKUPPC_USER@,${BACKUPPC_USER},g'
SUBST_SED.fix-paths+=		-e 's,@BACKUPPC_GROUP@,${BACKUPPC_GROUP},g'
SUBST_SED.fix-paths+=		-e 's,@PERL5@,${PERL5},g'

FILES_SUBST+=			BACKUPPC_USER=${BACKUPPC_USER:Q} BACKUPPC_GROUP=${BACKUPPC_GROUP:Q}

PKG_SYSCONFSUBDIR=	BackupPC
PKG_SYSCONFDIR_PERMS=   ${BACKUPPC_USER} ${BACKUPPC_GROUP} 0755
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

do-build:
	rm -rf ${WRKSRC}/build/${VARBASE}

do-install:
	cd ${WRKSRC}/build && pax -rw . ${DESTDIR}/
	chmod +x ${DESTDIR}${PREFIX}/share/BackupPC/bin/*
	${INSTALL_DATA} ${WRKSRC}/backuppc.conf ${DESTDIR}${PREFIX}/share/examples/BackupPC/backuppc.conf
	${INSTALL_DATA} ${WRKSRC}/cgiwrapper.c ${DESTDIR}${PREFIX}/share/examples/BackupPC/cgiwrapper.c

.include "../../mk/bsd.pkg.mk"
