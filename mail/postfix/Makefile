# $NetBSD: Makefile,v 1.65 2002/06/17 19:42:08 tron Exp $

DISTNAME=	postfix-1.1.11
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.porcupine.org/mirrors/postfix-release/official/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.postfix.org/
COMMENT=	Postfix SMTP server and tools

DIST_SUBDIR=	postfix

POSTFIX_SPOOL=	/var/spool/postfix

.include "../../mk/bsd.prefs.mk"

# XXX No IPv6 patch available yet!
#
# .if defined(POSTFIX_USE_INET6) && ${POSTFIX_USE_INET6} == "YES"
# PATCHFILES+=	postfix-20010228pl04-v6-20010809a.diff.gz
# PATCH_SITES+=	ftp://ftp.kame.net/pub/kame/misc/
# BUILD_DEFS+=	POSTFIX_USE_INET6
# .endif

.if defined(POSTFIX_USE_PCRE) && ${POSTFIX_USE_PCRE} == "YES" \
	|| defined(USE_SASL) && ${USE_SASL} == "YES" \
	|| defined(POSTFIX_USE_MYSQL) && ${POSTFIX_USE_MYSQL} == "YES"
CCARGS=		-I${LOCALBASE}/include
AUXLIBS=	-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib
MAKE_ENV+=	AUXLIBS="${AUXLIBS}" CCARGS="${CCARGS}"
.endif

.if defined(POSTFIX_USE_PCRE) && ${POSTFIX_USE_PCRE} == "YES"
DEPENDS+=	pcre>=2.08:../../devel/pcre
CCARGS+=	-DHAS_PCRE
AUXLIBS+=	-lpcre
BUILD_DEFS+=	POSTFIX_USE_PCRE
.endif

.if defined(POSTFIX_USE_MYSQL) && ${POSTFIX_USE_MYSQL} == "YES"
DEPENDS+=	mysql-client>=3.23:../../databases/mysql-client
CCARGS+=	-DHAS_MYSQL -I${LOCALBASE}/include/mysql
AUXLIBS+=	-L${LOCALBASE}/lib/mysql -Wl,-R${LOCALBASE}/lib/mysql
AUXLIBS+=	-lmysqlclient -lz -lm
BUILD_DEFS+=	POSTFIX_USE_MYSQL
.endif

.if defined(USE_SASL) && ${USE_SASL} == "YES"
DEPENDS+=	cyrus-sasl:../../security/cyrus-sasl
CCARGS+=	-DUSE_SASL_AUTH
AUXLIBS+=	-lsasl
PLIST_SRC+=	${WRKDIR}/PLIST.sasl
MESSAGE_SRC+=	${PKGDIR}/MESSAGE.sasl
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
BUILD_DEFS+=	USE_SASL
.endif

PLIST_SRC+=	${PKGDIR}/PLIST
ALL_TARGET=	#empty
MAKE_ENV=	CC="${CC}" OPT="${CFLAGS}"

pre-configure:
	${CP} ${WRKSRC}/conf/main.cf ${WRKSRC}/conf/main.cf.dist
	${SED} -e 's:__PREFIX:'${PREFIX}':g' \
	    < ${WRKSRC}/conf/main.cf.dist \
	    > ${WRKSRC}/conf/main.cf
	${CP} ${WRKSRC}/src/util/sys_defs.h ${WRKSRC}/src/util/sys_defs.h.dist
	${SED} -e 's:__PREFIX:'${PREFIX}':g' \
	    < ${WRKSRC}/src/util/sys_defs.h.dist \
	    > ${WRKSRC}/src/util/sys_defs.h
	${CP} ${WRKSRC}/postfix-install ${WRKSRC}/postfix-install.dist
	${SED} -e 's:__PREFIX:'${PREFIX}':g' \
	    < ${WRKSRC}/postfix-install.dist \
	    > ${WRKSRC}/postfix-install
	${CP} ${WRKSRC}/conf/sample-misc.cf ${WRKSRC}/conf/sample-misc.cf.dist
	${SED} -e 's:__PREFIX:'${PREFIX}':g' \
	    < ${WRKSRC}/conf/sample-misc.cf.dist \
	    > ${WRKSRC}/conf/sample-misc.cf
	${CP} ${WRKSRC}/src/global/mail_params.h \
		${WRKSRC}/src/global/mail_params.h.dist
	${SED} -e 's:__PREFIX:'${PREFIX}':g' \
	    < ${WRKSRC}/src/global/mail_params.h.dist \
	    > ${WRKSRC}/src/global/mail_params.h

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} makefiles)

post-build:
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	    <${FILESDIR}/mailer.conf >${WRKDIR}/mailer.conf.postfix

pre-install:
	${INSTALL_DATA_DIR} /etc/postfix
	${INSTALL_DATA_DIR} ${PREFIX}/share/postfix
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/postfix
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/postfix
	${CHOWN} ${ROOT_USER}:${ROOT_GROUP} ${PREFIX}/share/postfix \
	    ${PREFIX}/libexec/postfix
	${CHMOD} 755 ${PREFIX}/share/postfix ${PREFIX}/libexec/postfix
	-${RM} -f ${WRKSRC}/conf/*.orig
.if defined(USE_SASL) && ${USE_SASL} == "YES"
	${ECHO} "pwcheck_method: sasldb" > ${WRKDIR}/smtpd.conf
	${INSTALL_DATA} ${WRKDIR}/smtpd.conf ${PREFIX}/lib/sasl
	${ECHO} lib/sasl/smtpd.conf > ${WRKDIR}/PLIST.sasl
.endif
	${TEST} -f /etc/postfix/postfix-files || \
		${INSTALL_DATA} ${WRKSRC}/conf/postfix-files /etc/postfix
	${TEST} -f /etc/postfix/postfix-script || \
		${INSTALL_DATA} ${WRKSRC}/conf/postfix-script /etc/postfix
	${TEST} -f /etc/postfix/main.cf || \
		${INSTALL_DATA} ${WRKSRC}/conf/main.cf /etc/postfix
	${TEST} -f /etc/postfix/master.cf || \
		${INSTALL_DATA} ${WRKSRC}/conf/master.cf /etc/postfix

do-install:
	(cd ${WRKSRC} && ${SH} postfix-install -non-interactive)

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/main.cf ${PREFIX}/share/postfix
	${INSTALL_DATA} ${WRKSRC}/conf/master.cf ${PREFIX}/share/postfix
	${INSTALL_SCRIPT} ${WRKSRC}/conf/post-install ${PREFIX}/share/postfix
	${INSTALL_SCRIPT} ${WRKSRC}/conf/postfix-files ${PREFIX}/share/postfix
	${INSTALL_SCRIPT} ${WRKSRC}/conf/postfix-script ${PREFIX}/share/postfix
	${INSTALL_DATA} ${WRKDIR}/mailer.conf.postfix ${PREFIX}/etc
	${LN} -sf ${PREFIX}/share/postfix/post-install /etc/postfix
	${LN} -sf ${PREFIX}/share/postfix/postfix-files /etc/postfix
	${LN} -sf ${PREFIX}/share/postfix/postfix-script /etc/postfix
	${INSTALL_DATA_DIR} ${POSTFIX_SPOOL}
	${CHMOD} 755 ${POSTFIX_SPOOL}
	${TEST} -f /etc/postfix/main.cf || \
		${INSTALL_DATA} ${PREFIX}/share/postfix/main.cf /etc/postfix
	${TEST} -f /etc/postfix/master.cf || \
		${INSTALL_DATA} ${PREFIX}/share/postfix/master.cf /etc/postfix

.include "../../mk/bsd.pkg.mk"
