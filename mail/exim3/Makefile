# $NetBSD: Makefile,v 1.18 2005/04/28 22:46:11 jlam Exp $

DISTNAME=	exim-3.36
PKGREVISION=	4
CATEGORIES=	mail net
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/exim3/ \
		http://public.planetmirror.com.au/pub/exim/exim3/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://www.exim.org/
COMMENT=	The Exim mail transfer agent, a replacement for sendmail

CONFLICTS+=	exim-exiscan-[0-9]*

USE_PERL5=	YES
USE_PKGINSTALL=	YES

BUILD_DEFS+=		EXIM_USER EXIM_GROUP
BUILD_DEFS+=		EXIM_DB.mysql EXIM_DB.pgsql

PKG_SYSCONFSUBDIR?=	exim
EGDIR=			${PREFIX}/share/examples/exim
MAKE_ENV+=		INST_CONFIGURE_FILE="${EGDIR}/configure"
CONF_FILES=		${EGDIR}/configure ${PKG_SYSCONFDIR}/configure
MESSAGE_SUBST+=		EGDIR="${EGDIR}"

RCD_SCRIPTS=		exim

OWN_DIRS_PERMS=		/var/log/exim ${EXIM_USER} ${EXIM_GROUP} 0750
OWN_DIRS_PERMS+=	/var/spool/exim ${EXIM_USER} ${EXIM_GROUP} 0750

PKG_USERS=		${EXIM_USER}:${EXIM_GROUP}:8:Exim\\ mail\\ server\\ user:/var/mail:/sbin/nologin
PKG_GROUPS=		${EXIM_GROUP}

.include "../../mk/bsd.prefs.mk"

FILES_SUBST+=		GZIP_CMD="${GZIP_CMD:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}"
FILES_SUBST+=		GZCAT="${GZCAT}"

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
DBMLIB+=		${BDB_LIBS}

MAKE_ENV+=		DBMLIB=${DBMLIB:Q}
MAKE_ENV+=		LOOKUP_INCLUDE="${LOOKUP_INCLUDE}"
MAKE_ENV+=		LOOKUP_LIBS="${LOOKUP_LIBS}"

pre-patch:
	${MKDIR} ${WRKSRC}/Local
	${CP} ${WRKSRC}/src/EDITME ${WRKSRC}/Local/Makefile.netbsd

pre-configure:
	@${SED} ${FILES_SUBST_SED} ${WRKSRC}/Local/Makefile.netbsd \
		> ${WRKSRC}/Local/Makefile
	@for f in ${WRKSRC}/OS/Makefile-*; do \
		${SED} -e 's/^CFLAGS.*/& $$(CPPFLAGS)/' \
		-e '/^DBMLIB/d' $$f > $$f.subst; \
		${MV} -f $$f.subst $$f; \
	done

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/mailer.conf.exim \
		> ${WRKDIR}/mailer.conf

post-install:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/exim_newaliases \
		> ${PREFIX}/sbin/exim_newaliases
	${CHMOD} ugo+x ${PREFIX}/sbin/exim_newaliases
	${INSTALL_DATA} ${WRKDIR}/mailer.conf ${EGDIR}
	${CP} ${FILESDIR}/exim.8 ${PREFIX}/man/man8/exim.8

.include "../../mk/bsd.pkg.mk"
