# $NetBSD: Makefile,v 1.4 2003/12/04 05:14:30 grant Exp $

DISTNAME=	exim-3.36
CATEGORIES=	mail net
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/exim3/ \
		http://public.planetmirror.com.au/pub/exim/exim3/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://www.exim.org/
COMMENT=	The Exim mail transfer agent, a replacement for sendmail

USE_BUILDLINK2=	YES
USE_PERL5=	YES
USE_PKGINSTALL=	YES

BUILD_DEFS+=		EXIM_USER EXIM_GROUP
BUILD_DEFS+=		EXIM_DB.db1 EXIM_DB.mysql EXIM_DB.pgsql

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

_GZIP_CMD!=		${ECHO} ${GZIP_CMD} | ${SED} -e 's/ .*//'
FILES_SUBST+=		GZIP_CMD="${_GZIP_CMD}"
FILES_SUBST+=		GZCAT="${GZCAT}"

_LOOKUP_LIBS+=		${LDFLAGS}

# default to using db1 on platforms which have it.
EXIM_DB.db1?=		YES
.if ${EXIM_DB.db1} == "YES"
USE_DB185=		YES
.endif

.if defined(EXIM_DB.mysql) && ${EXIM_DB.mysql} == "YES"
LOOKUP_INCLUDE+=	-I${BUILDLINK_PREFIX.mysql-client}/include/mysql
LOOKUP_LIBS+=		${BUILDLINK_LDFLAGS.mysql-client} -lmysqlclient
MAKE_ENV+=		LOOKUP_MYSQL=YES
.  include "../../databases/mysql-client/buildlink2.mk"
.endif
.if defined(EXIM_DB.pgsql) && ${EXIM_DB.pgsql} == "YES"
LOOKUP_INCLUDE+=	-I${BUILDLINK_PREFIX.postgresql-lib}/include/postgresql
LOOKUP_LIBS+=		-lpq
MAKE_ENV+=		LOOKUP_PGSQL=YES
.  include "../../databases/postgresql-lib/buildlink2.mk"
.endif

# buildlink2 decides which libdb to use on this platform.
MAKE_ENV+=		DBMLIB="${BUILDLINK_LDFLAGS.db} ${BUILDLINK_LIBS.db}"
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

.include "../../databases/db/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
