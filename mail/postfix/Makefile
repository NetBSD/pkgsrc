# $NetBSD: Makefile,v 1.91 2003/04/17 06:22:18 martti Exp $

DISTNAME=	postfix-2.0.8
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.porcupine.org/mirrors/postfix-release/official/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.postfix.org/
COMMENT=	Postfix SMTP server and tools

DIST_SUBDIR=	postfix

POSTFIX_SPOOL=	/var/spool/postfix

USE_BUILDLINK2=	yes
USE_PKGINSTALL=	yes

PKG_SYSCONFSUBDIR=	postfix

CCARGS+=	-DDEF_CONFIG_DIR=\"${PKG_SYSCONFDIR}\"
CCARGS+=	-DDEF_SENDMAIL_PATH=\"${PREFIX}/sbin/sendmail\"
CCARGS+=	-DDEF_MAILQ_PATH=\"${PREFIX}/bin/mailq\"
CCARGS+=	-DDEF_NEWALIAS_PATH=\"${PREFIX}/bin/newaliases\"
CCARGS+=	-DDEF_COMMAND_DIR=\"${PREFIX}/sbin\"
CCARGS+=	-DDEF_DAEMON_DIR=\"${LIBEXECDIR}\"

.include "../../mk/bsd.prefs.mk"

FIX_RPATH+=	AUXLIBS

#.if defined(POSTFIX_USE_INET6) && ${POSTFIX_USE_INET6} == "YES"
#PATCHFILES+=		tls+ipv6-1.13-pf-2.0.7.patch.gz
#PATCH_SITES+=		ftp://ftp.stack.nl/pub/postfix/tls+ipv6/1.13/
#PATCH_DIST_STRIP=	-p1
#BUILD_DEFS+=		POSTFIX_USE_INET6
#
#CCARGS+=		-DHAS_SSL
#AUXLIBS+=		-L${BUILDLINK_PREFIX.openssl}/lib	\
#			-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib \
#			-lssl -lcrypto
#BUILD_DEFS+=		POSTFIX_USE_TLS
#
#PLIST_SRC+=		${PKGDIR}/PLIST.tls
#MESSAGE_SRC+=		${PKGDIR}/MESSAGE.tls
#.endif

.if defined(POSTFIX_USE_PCRE) && ${POSTFIX_USE_PCRE} == "YES"
.include "../../devel/pcre/buildlink2.mk"
CCARGS+=	-DHAS_PCRE
AUXLIBS+=	-L${BUILDLINK_PREFIX.pcre}/lib		\
		-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.pcre}/lib	\
		-lpcre
BUILD_DEFS+=	POSTFIX_USE_PCRE
.else
CCARGS+=	-DNO_PCRE
.endif

.if defined(POSTFIX_USE_LDAP) && ${POSTFIX_USE_LDAP} == "YES"
.include "../../databases/openldap/buildlink2.mk"
CCARGS+=	-DHAS_LDAP
AUXLIBS+=	-L${BUILDLINK_PREFIX.openldap}/lib	\
		-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.openldap}/lib	\
		-lldap -llber
BUILD_DEFS+=	POSTFIX_USE_LDAP
.endif

.if defined(POSTFIX_USE_MYSQL) && ${POSTFIX_USE_MYSQL} == "YES"
.include "../../databases/mysql-client/buildlink2.mk"
CCARGS+=	-DHAS_MYSQL -I${BUILDLINK_PREFIX.mysql-client}/include/mysql
AUXLIBS+=	-L${BUILDLINK_PREFIX.mysql-client}/lib/mysql		\
		-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.mysql-client}/lib/mysql	\
		-lmysqlclient -lz -lm
BUILD_DEFS+=	POSTFIX_USE_MYSQL
.endif

#.if defined(POSTFIX_USE_TLS) && ${POSTFIX_USE_TLS} == "YES"
#.include "../../security/openssl/buildlink2.mk"
#PATCH_SITES+=	http://people.arhea.net/dawszy/NetBSD/postfix_tls/
#PATCHFILES+=	pfixtls-1.1.11.diff.gz
#PATCH_DIST_STRIP=	-p1
#
#CCARGS+=	-DHAS_SSL
#AUXLIBS+=	-L${BUILDLINK_PREFIX.openssl}/lib	\
#		-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib	\
#		-lssl -lcrypto
#BUILD_DEFS+=	POSTFIX_USE_TLS
#
#PLIST_SRC+=	${PKGDIR}/PLIST.tls
#MESSAGE_SRC+=	${PKGDIR}/MESSAGE.tls
#.endif

.if defined(USE_SASL) && ${USE_SASL} == "YES"
.include "../../security/cyrus-sasl/buildlink2.mk"
CCARGS+=	-DUSE_SASL_AUTH
AUXLIBS+=	-L${BUILDLINK_PREFIX.cyrus-sasl}/lib		\
		-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.cyrus-sasl}/lib	\
		-lsasl
BUILD_DEFS+=	USE_SASL

PLIST_SRC+=	${WRKDIR}/PLIST.sasl
MESSAGE_SRC+=	${PKGDIR}/MESSAGE.sasl
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
.endif

MESSAGE_SRC+=	${PKGDIR}/MESSAGE
PLIST_SRC+=	${PKGDIR}/PLIST
ALL_TARGET=	#empty
MAKE_ENV=	CC="${CC}" OPT="${CFLAGS}"
MAKE_ENV+=	AUXLIBS="${AUXLIBS}" CCARGS="${CCARGS}"

POSTFIX_CONF_FILES=	conf/main.cf src/util/sys_defs.h postfix-install
POSTFIX_CONF_FILES+=	conf/sample-misc.cf src/global/mail_params.h

PLIST_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
PLIST_SUBST+=	POSTFIX_SPOOL=${POSTFIX_SPOOL}

PKG_GROUPS?=	postfix maildrop
PKG_USERS?=	postfix:postfix::Postfix\\ User:${POSTFIX_SPOOL}

LIBEXECDIR=	${PREFIX}/libexec/${PKGBASE}
SHAREDIR=	${PREFIX}/share/${PKGBASE}

CONF_FILES+=	${SHAREDIR}/main.cf ${PKG_SYSCONFDIR}/main.cf
CONF_FILES+=	${SHAREDIR}/master.cf ${PKG_SYSCONFDIR}/master.cf

pre-configure:
	@for i in ${POSTFIX_CONF_FILES}; do				\
		${CP} ${WRKSRC}/$${i} ${WRKSRC}/$${i}.dist;		\
		${SED} -e 's|__PREFIX|'${PREFIX}'|g'			\
			-e 's|__PKG_SYSCONFDIR|'${PKG_SYSCONFDIR}'|g'	\
			< ${WRKSRC}/$${i}.dist				\
			> ${WRKSRC}/$${i};				\
	done

do-configure:
	(cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${MAKE} -f Makefile.init makefiles \
		'CCARGS=${CCARGS}' 'AUXLIBS=${AUXLIBS}')

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
.if defined(USE_SASL) && ${USE_SASL} == "YES"
	${ECHO} "pwcheck_method: sasldb" > ${WRKDIR}/smtpd.conf
	${INSTALL_DATA} ${WRKDIR}/smtpd.conf ${PREFIX}/lib/sasl
	${ECHO} lib/sasl/smtpd.conf > ${WRKDIR}/PLIST.sasl
.endif
	for pf in postfix-files postfix-script main.cf master.cf; do \
		${TEST} -f ${PKG_SYSCONFDIR}/$$pf || \
		    ${INSTALL_DATA} ${WRKSRC}/conf/$$pf ${PKG_SYSCONFDIR}; \
	done

do-install:
	(cd ${WRKSRC} && ${SH} postfix-install -non-interactive)

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/main.cf ${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/master.cf ${SHAREDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/conf/post-install ${SHAREDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/conf/postfix-files ${SHAREDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/conf/postfix-script ${SHAREDIR}
	${INSTALL_DATA} ${WRKDIR}/mailer.conf.postfix ${PREFIX}/etc
	${LN} -sf ${SHAREDIR}/post-install ${PKG_SYSCONFDIR}
	${LN} -sf ${SHAREDIR}/postfix-files ${PKG_SYSCONFDIR}
	${LN} -sf ${SHAREDIR}/postfix-script ${PKG_SYSCONFDIR}
	${INSTALL_DATA_DIR} ${POSTFIX_SPOOL}
	${CHMOD} 755 ${POSTFIX_SPOOL}

.include "../../mk/bsd.pkg.mk"
