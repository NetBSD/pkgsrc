# $NetBSD: Makefile,v 1.55 2019/08/11 13:21:27 wiz Exp $

DISTNAME=	exim-3.36
PKGREVISION=	20
CATEGORIES=	mail net
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/exim3/
MASTER_SITES+=	http://public.planetmirror.com.au/pub/exim/exim3/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.exim.org/
COMMENT=	The Exim mail transfer agent, a replacement for sendmail

MAKE_JOBS_SAFE=		no

CONFLICTS+=	exim-exiscan-[0-9]*

BUILD_DEFS+=		EXIM_DB.mysql EXIM_DB.pgsql

PKG_SYSCONFSUBDIR?=	exim
EGDIR=			${PREFIX}/share/examples/exim
CONF_FILES=		${EGDIR}/configure ${PKG_SYSCONFDIR}/configure
MESSAGE_SUBST+=		EGDIR="${EGDIR}"

RCD_SCRIPTS=		exim

OWN_DIRS_PERMS=		/var/log/exim ${EXIM_USER} ${EXIM_GROUP} 0750
OWN_DIRS_PERMS+=	/var/spool/exim ${EXIM_USER} ${EXIM_GROUP} 0750

PKG_GROUPS=		${EXIM_GROUP}
PKG_USERS=		${EXIM_USER}:${EXIM_GROUP}

PKG_GROUPS_VARS+=	EXIM_GROUP
PKG_USERS_VARS+=	EXIM_USER

PKG_UID.${EXIM_USER}?=	8
PKG_GECOS.${EXIM_USER}=	Exim mail server user
PKG_HOME.${EXIM_USER}=	${VARBASE}/mail
PKG_SHELL.${EXIM_USER}=	${NOLOGIN}

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		gzip gzcat perl:run
FILES_SUBST+=		GZIP_CMD="${GZIP_CMD:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}"
FILES_SUBST+=		GZCAT=${GZCAT:Q}

_LOOKUP_LIBS+=		${LDFLAGS}

.if defined(EXIM_DB.mysql) && ${EXIM_DB.mysql} == "YES"
LOOKUP_INCLUDE+=	-I${BUILDLINK_PREFIX.mysql-client}/include/mysql
LOOKUP_LIBS+=		-L${BUILDLINK_PREFIX.mysql-client}/lib/mysql
LOOKUP_LIBS+=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.mysql-client}/lib/mysql
LOOKUP_LIBS+=		-lmysqlclient
MAKE_ENV+=		LOOKUP_MYSQL=YES
.  include "../../mk/mysql.buildlink3.mk"
.endif
.if defined(EXIM_DB.pgsql) && ${EXIM_DB.pgsql} == "YES"
LOOKUP_INCLUDE+=	-I${PGSQL_PREFIX}/include/postgresql
LOOKUP_LIBS+=		-L${PGSQL_PREFIX}/lib
LOOKUP_LIBS+=		${COMPILER_RPATH_FLAG}${PGSQL_PREFIX}/lib -lpq
MAKE_ENV+=		LOOKUP_PGSQL=YES
.  include "../../mk/pgsql.buildlink3.mk"
.endif

BDB_ACCEPTED=	db1 db3 db2	# does not compile with db4
.include "../../mk/bdb.buildlink3.mk"
DBMLIB+=		${LDFLAGS} ${BDB_LIBS}

MAKE_ENV+=		DBMLIB=${DBMLIB:Q}
MAKE_ENV+=		LOOKUP_INCLUDE=${LOOKUP_INCLUDE:Q}
MAKE_ENV+=		LOOKUP_LIBS=${LOOKUP_LIBS:Q}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	Local/Makefile.pkgsrc ${WRKDIR}/mailer.conf
SUBST_FILES.paths+=	${WRKDIR}/exim_newaliases
SUBST_VARS.paths=	PREFIX
SUBST_VARS.paths+=	PKG_SYSCONFDIR
SUBST_VARS.paths+=	GZIP_CMD
SUBST_VARS.paths+=	GZCAT
SUBST_VARS.paths+=	PERL5
SUBST_VARS.paths+=	SH
SUBST_STAGE.paths=	pre-configure

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin share/examples/exim

INSTALL_ENV+=	INST_BIN_DIRECTORY=${DESTDIR}${PREFIX}/sbin \
	INST_CONFIGURE_FILE=${DESTDIR}${EGDIR}/configure \
	INST_UID=${ROOT_USER}

post-extract:
	${CP} ${FILESDIR}/Makefile-DragonFly ${FILESDIR}/os.h-DragonFly \
		${WRKSRC}/OS/
	${CP} ${FILESDIR}/mailer.conf.exim ${WRKDIR}/mailer.conf
	${CP} ${FILESDIR}/exim_newaliases ${WRKDIR}/exim_newaliases

pre-patch:
	${MKDIR} ${WRKSRC}/Local
	${CP} ${WRKSRC}/src/EDITME ${WRKSRC}/Local/Makefile.pkgsrc

pre-configure:
	${CP} ${WRKSRC}/Local/Makefile.pkgsrc ${WRKSRC}/Local/Makefile
	@for f in ${WRKSRC}/OS/Makefile-*; do \
		${SED} -e 's/^CFLAGS.*/& $$(CPPFLAGS)/' \
		-e '/^DBMLIB/d' $$f > $$f.subst; \
		${MV} -f $$f.subst $$f; \
	done

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/exim_newaliases ${DESTDIR}${PREFIX}/sbin/exim_newaliases
	${INSTALL_DATA} ${WRKDIR}/mailer.conf ${DESTDIR}${EGDIR}
	${CP} ${FILESDIR}/exim.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/exim.8

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
