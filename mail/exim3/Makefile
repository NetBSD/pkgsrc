# $NetBSD: Makefile,v 1.1.1.1 2003/12/04 04:24:49 grant Exp $

DISTNAME=	exim-3.36
CATEGORIES=	mail net
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/exim3/ \
		http://public.planetmirror.com.au/pub/exim/exim3/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ad@NetBSD.org
HOMEPAGE=	http://www.exim.org/
COMMENT=	The Exim mail transfer agent, a replacement for sendmail

USE_BUILDLINK2=	YES
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

_GZIP_CMD!=		${ECHO} ${GZIP_CMD} | ${SED} -e 's/ .*//'
FILES_SUBST+=		GZIP_CMD="${_GZIP_CMD}"
FILES_SUBST+=		GZCAT="${GZCAT}"

_LOOKUP_LIBS+=		${LDFLAGS}

.if defined(EXIM_DB.mysql) && ${EXIM_DB.mysql} == "YES"
_EXIM_DB+=		mysql
_LOOKUP_INCLUDE+=	-I${BUILDLINK_PREFIX.mysql-client}/include/mysql
_LOOKUP_LIBS+=		${BUILDLINK_LDFLAGS.mysql-client} -lmysqlclient
.  include "../../databases/mysql-client/buildlink2.mk"
.endif
.if defined(EXIM_DB.pgsql) && ${EXIM_DB.pgsql} == "YES"
_EXIM_DB+=		pgsql
_LOOKUP_INCLUDE+=	-I${BUILDLINK_PREFIX.postgresql-lib}/include/postgresql
_LOOKUP_LIBS+=		-lpq
.  include "../../databases/postgresql-lib/buildlink2.mk"
.endif

pre-patch:
	${MKDIR} ${WRKSRC}/Local
	${CP} ${WRKSRC}/src/EDITME ${WRKSRC}/Local/Makefile.netbsd

pre-configure:
	@${SED} ${FILES_SUBST_SED} ${WRKSRC}/Local/Makefile.netbsd \
		> ${WRKSRC}/Local/Makefile
	for f in ${WRKSRC}/OS/Makefile-*; do \
		${SED} -e 's/^CFLAGS.*/& $$(CPPFLAGS)/' $$f > $$f.cppsubst; \
		${MV} -f $$f.cppsubst $$f; \
	done
.if defined(_EXIM_DB)
	@${ECHO} LOOKUP_INCLUDE=${_LOOKUP_INCLUDE} >> ${WRKSRC}/Local/Makefile
	@${ECHO} LOOKUP_LIBS=${_LOOKUP_LIBS} >> ${WRKSRC}/Local/Makefile
.  if !empty(_EXIM_DB:Mmysql)
	@${ECHO} LOOKUP_MYSQL=yes >> ${WRKSRC}/Local/Makefile
.  endif
.  if !empty(_EXIM_DB:Mpgsql)
	@${ECHO} LOOKUP_PGSQL=yes >> ${WRKSRC}/Local/Makefile
.  endif
.endif

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
