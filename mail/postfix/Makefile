# $NetBSD: Makefile,v 1.129 2004/04/21 21:09:31 cube Exp $

DISTNAME=	postfix-2.0.19
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.porcupine.org/mirrors/postfix-release/official/

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.postfix.org/
COMMENT=	Postfix SMTP server and tools

CONFLICTS+=	sendmail-[0-9]*

DIST_SUBDIR=	postfix

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
USE_PKGINSTALL=	yes

PKG_SYSCONFSUBDIR=	postfix
POSTFIX_SPOOL=		/var/spool/postfix

OWN_DIRS=	${POSTFIX_SPOOL}

CCARGS+=	-DDEF_CONFIG_DIR=\"${PKG_SYSCONFDIR}\"
CCARGS+=	-DDEF_SENDMAIL_PATH=\"${PREFIX}/sbin/sendmail\"
CCARGS+=	-DDEF_MAILQ_PATH=\"${PREFIX}/bin/mailq\"
CCARGS+=	-DDEF_NEWALIAS_PATH=\"${PREFIX}/bin/newaliases\"
CCARGS+=	-DDEF_COMMAND_DIR=\"${PREFIX}/sbin\"
CCARGS+=	-DDEF_DAEMON_DIR=\"${LIBEXECDIR}\"

.include "../../mk/bsd.prefs.mk"

# NetBSD 1.5 and above has /etc/rc.d/postfix already which is
# suitable.
.if empty(MACHINE_PLATFORM:MNetBSD-1.[5-9]*-*)
RCD_SCRIPTS=	postfix
.endif

FIX_RPATH+=	AUXLIBS

BUILD_DEFS+=	POSTFIX_USE_INET6
BUILD_DEFS+=	POSTFIX_USE_TLS
BUILD_DEFS+=	POSTFIX_USE_PCRE
BUILD_DEFS+=	POSTFIX_USE_MYSQL
BUILD_DEFS+=	POSTFIX_USE_PGSQL
BUILD_DEFS+=	USE_OPENLDAP
BUILD_DEFS+=	USE_SASL
BUILD_DEFS+=	USE_SASL2

.if defined(POSTFIX_USE_INET6) && ${POSTFIX_USE_INET6} == "YES"
.  include "../../security/openssl/buildlink3.mk"
PATCHFILES+=		tls+ipv6-1.22-pf-2.0.19.patch.gz
PATCH_SITES+=		ftp://ftp.stack.nl/pub/postfix/tls+ipv6/1.22/
PATCH_DIST_STRIP=	-p1

CCARGS+=	-DHAS_SSL
AUXLIBS+=	-L${BUILDLINK_PREFIX.openssl}/lib			\
		-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib	\
		-lssl -lcrypto

PLIST_SRC+=	${PKGDIR}/PLIST.tls
MESSAGE_SRC+=	${PKGDIR}/MESSAGE.tls
.endif

.if defined(POSTFIX_USE_PCRE) && ${POSTFIX_USE_PCRE} == "YES"
.  include "../../devel/pcre/buildlink3.mk"
CCARGS+=	-DHAS_PCRE
AUXLIBS+=	-L${BUILDLINK_PREFIX.pcre}/lib				\
		-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.pcre}/lib		\
		-lpcre
.else
CCARGS+=	-DNO_PCRE
.endif

.if defined(USE_OPENLDAP) && ${USE_OPENLDAP} == "YES"
.  include "../../databases/openldap/buildlink3.mk"
CCARGS+=	-DHAS_LDAP
AUXLIBS+=	-L${BUILDLINK_PREFIX.openldap}/lib			\
		-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.openldap}/lib	\
		-lldap -llber
.  if ${OPSYS} != "Linux"
.    include "../../databases/db4/buildlink3.mk"
CCARGS+=	-I${BUILDLINK_PREFIX.db4}/include/db4
AUXLIBS+=	-L${BUILDLINK_PREFIX.db4}/lib                    \
		-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.db4}/lib     \
		-ldb4
.  endif
.endif

.if defined(POSTFIX_USE_MYSQL) && ${POSTFIX_USE_MYSQL} == "YES"
.  include "../../databases/mysql-client/buildlink3.mk"
CCARGS+=	-DHAS_MYSQL -I${BUILDLINK_PREFIX.mysql-client}/include/mysql
AUXLIBS+=	-L${BUILDLINK_PREFIX.mysql-client}/lib/mysql		\
		-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.mysql-client}/lib/mysql	\
		-lmysqlclient -lz -lm
.endif

.if defined(POSTFIX_USE_PGSQL) && ${POSTFIX_USE_PGSQL} == "YES"
.  include "../../databases/postgresql-lib/buildlink3.mk"
.  include "../../security/openssl/buildlink3.mk"
PATCHFILES+=		postfix-pg.postfix-2.0.0.2.patch
PATCH_SITES+=		http://www.mat.cc/postfix/
PATCH_DIST_STRIP=	-p1

CCARGS+=	-DHAS_PGSQL -I${BUILDLINK_PREFIX.postgresql-lib}/include/pgsql
AUXLIBS+=	-L${BUILDLINK_PREFIX.postgresql-lib}/lib -lpq \
		-L${BUILDLINK_PREFIX.openssl}/lib -lcrypt
.endif

.if defined(USE_SASL2) && ${USE_SASL2} == "YES"
USING_SASL=	YES
.  include "../../security/cyrus-sasl2/buildlink3.mk"
CCARGS+=	-DUSE_SASL2_AUTH
AUXLIBS+=	-L${BUILDLINK_PREFIX.cyrus-sasl}/lib			\
		-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.cyrus-sasl}/lib	\
		-lsasl2
.elif defined(USE_SASL) && ${USE_SASL} == "YES"
USING_SASL=YES
.  include "../../security/cyrus-sasl/buildlink3.mk"
CCARGS+=	-DUSE_SASL_AUTH
AUXLIBS+=	-L${BUILDLINK_PREFIX.cyrus-sasl}/lib			\
		-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.cyrus-sasl}/lib	\
		-lsasl
.endif

.if defined(USING_SASL)
PLIST_SRC+=	${PKGDIR}/PLIST.sasl
MESSAGE_SRC+=	${PKGDIR}/MESSAGE.sasl
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
.endif

MESSAGE_SRC+=	${PKGDIR}/MESSAGE
.if exists(${PKGDIR}/MESSAGE.${OPSYS})
MESSAGE_SRC+=	${PKGDIR}/MESSAGE.${OPSYS}
.endif
PLIST_SRC+=	${PKGDIR}/PLIST
ALL_TARGET=	#empty
MAKE_ENV=	CC="${CC}" OPT="${CFLAGS}"
MAKE_ENV+=	AUXLIBS="${AUXLIBS}" CCARGS="${CCARGS}"

POSTFIX_CONF_FILES=	conf/main.cf src/util/sys_defs.h postfix-install
POSTFIX_CONF_FILES+=	conf/sample-misc.cf src/global/mail_params.h

FILES_SUBST+=	SHAREDIR=${SHAREDIR}
MESSAGE_SUBST+=	SHAREDIR=${SHAREDIR}
PLIST_SUBST+=	POSTFIX_SPOOL=${POSTFIX_SPOOL}

PKG_GROUPS?=	postfix maildrop
PKG_USERS?=	postfix:postfix::Postfix\\ User:${POSTFIX_SPOOL}

LIBEXECDIR=	${PREFIX}/libexec/${PKGBASE}
SHAREDIR=	${PREFIX}/share/examples/${PKGBASE}

CONF_FILES=	${SHAREDIR}/main.cf ${PKG_SYSCONFDIR}/main.cf
CONF_FILES+=	${SHAREDIR}/master.cf ${PKG_SYSCONFDIR}/master.cf
.if defined(USING_SASL)
.  if defined(USE_SASL2)
MAKE_DIRS+=	${PREFIX}/lib/sasl2
CONF_FILES+=	${SHAREDIR}/smtpd.conf	${PREFIX}/lib/sasl2/smtpd.conf
.  else
MAKE_DIRS+=	${PREFIX}/lib/sasl
CONF_FILES+=	${SHAREDIR}/smtpd.conf	${PREFIX}/lib/sasl/smtpd.conf
.  endif
.endif
CONF_FILES_PERMS=	# empty
.for confscr in post-install postfix-files postfix-script
CONF_FILES_PERMS+=	${SHAREDIR}/${confscr} ${PKG_SYSCONFDIR}/${confscr} \
			${ROOT_USER} ${ROOT_GROUP} 755
.endfor
.undef confscr

INSTALL_EXTRA_TMPL+=	${PKGDIR}/INSTALL

pre-configure:
	@for i in ${POSTFIX_CONF_FILES}; do				\
		${CP} ${WRKSRC}/$${i} ${WRKSRC}/$${i}.dist;		\
		${SED} -e 's|__PREFIX|'${PREFIX}'|g'			\
			-e 's|__PKG_SYSCONFDIR|'${PKG_SYSCONFDIR}'|g'	\
			< ${WRKSRC}/$${i}.dist				\
			> ${WRKSRC}/$${i};				\
	done

do-configure:
	cd ${WRKSRC} &&							\
	${SETENV} ${MAKE_ENV} ${MAKE} -f Makefile.init makefiles	\
		'CCARGS=${CCARGS}' 'AUXLIBS=${AUXLIBS}'

post-build:
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	    <${FILESDIR}/mailer.conf >${WRKDIR}/mailer.conf.postfix

pre-install:
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}
	${INSTALL_DATA_DIR} ${SHAREDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/postfix
	${INSTALL_DATA_DIR} ${LIBEXECDIR}
	${CHOWN} ${ROOT_USER}:${ROOT_GROUP} ${SHAREDIR} ${LIBEXECDIR}
	${CHMOD} 755 ${SHAREDIR} ${LIBEXECDIR}
	-${RM} -f ${WRKSRC}/conf/*.orig
.if defined(USING_SASL)
.  if defined(USE_SASL2)
	${ECHO} "pwcheck_method: auxprop" > ${WRKDIR}/smtpd.conf
.  else
	${ECHO} "pwcheck_method: sasldb" > ${WRKDIR}/smtpd.conf
.  endif
	${INSTALL_DATA} ${WRKDIR}/smtpd.conf ${SHAREDIR}
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/conf/post-install ${SHAREDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/conf/postfix-files ${SHAREDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/conf/postfix-script ${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/main.cf ${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/master.cf ${SHAREDIR}
	${INSTALL_DATA} ${WRKDIR}/mailer.conf.postfix ${SHAREDIR}/mailer.conf

do-install:
	cd ${WRKSRC} && ${SETENV} config_directory="${SHAREDIR}"	\
		${SH} postfix-install -non-interactive

.if ${OPSYS} == "Linux"
.  include "../../databases/db/buildlink3.mk"
CCARGS+=	-I${BUILDLINK_PREFIX.db2}/include/db2
AUXLIBS+=	-L${BUILDLINK_PREFIX.db2}/lib                    \
		-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.db2}/lib     \
		-ldb2
.endif

.include "../../mk/bsd.pkg.mk"
