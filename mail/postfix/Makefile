# $NetBSD: Makefile,v 1.51 2001/12/03 05:36:47 kent Exp $

DISTNAME=	postfix-20010228-pl08
PKGNAME=	postfix-20010228pl8
CATEGORIES=	mail
MASTER_SITES=	ftp://postfix.cloud9.net/official/

PATCHFILES=	postfix-20010228release-ercpt.diff
PATCH_SITES=	ftp://ftp.gw.com/pub/people/kim/patches/
PATCH_DIST_STRIP+=	-p1

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.postfix.org/
COMMENT=	Postfix SMTP server and tools

DIST_SUBDIR=	postfix

POSTFIX_SPOOL=	/var/spool/postfix

.include "../../mk/bsd.prefs.mk"

.if defined(POSTFIX_USE_INET6) && ${POSTFIX_USE_INET6} == "YES"
PATCHFILES+=	postfix-20010228pl04-v6-20010809a.diff.gz
PATCH_SITES+=	ftp://ftp.kame.net/pub/kame/misc/
BUILD_DEFS+=	POSTFIX_USE_INET6
.endif

.if defined(POSTFIX_USE_PCRE) && ${POSTFIX_USE_PCRE} == "YES" \
	|| defined(POSTFIX_USE_SASL_AUTH) && ${POSTFIX_USE_SASL_AUTH} == "YES"
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

.if defined(POSTFIX_USE_SASL_AUTH) && ${POSTFIX_USE_SASL_AUTH} == "YES"
DEPENDS+=	cyrus-sasl:../../security/cyrus-sasl
CCARGS+=	-DUSE_SASL_AUTH
AUXLIBS+=	-lsasl
PLIST_SRC+=	${WRKDIR}/PLIST.sasl
MESSAGE_SRC+=	${PKGDIR}/MESSAGE.sasl
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
BUILD_DEFS+=	POSTFIX_USE_SASL_AUTH
.endif

PLIST_SRC+=	${PKGDIR}/PLIST
ALL_TARGET=	#empty

pre-configure:
	${CP} ${WRKSRC}/conf/main.cf ${WRKSRC}/conf/main.cf.dist
	${CP} ${WRKSRC}/src/util/sys_defs.h ${WRKSRC}/src/util/sys_defs.h.dist
	${CP} ${WRKSRC}/INSTALL.sh ${WRKSRC}/INSTALL.sh.dist
	${SED} -e 's:__PREFIX:'${PREFIX}':g' \
	    < ${WRKSRC}/conf/main.cf.dist \
	    > ${WRKSRC}/conf/main.cf
	${SED} -e 's:__PREFIX:'${PREFIX}':g' \
	    < ${WRKSRC}/src/util/sys_defs.h.dist \
	    > ${WRKSRC}/src/util/sys_defs.h
	${SED} -e 's:__PREFIX:'${PREFIX}':g' \
	    < ${WRKSRC}/INSTALL.sh.dist \
	    > ${WRKSRC}/INSTALL.sh

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} makefiles)

post-build:
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	    <${FILESDIR}/mailer.conf >${WRKDIR}/mailer.conf.postfix

pre-install:
	${INSTALL_DATA_DIR} /etc/postfix ${PREFIX}/share/postfix \
	    ${PREFIX}/share/doc/postfix ${PREFIX}/libexec/postfix
	${CHOWN} root:wheel ${PREFIX}/share/postfix ${PREFIX}/libexec/postfix
	${CHMOD} 755 ${PREFIX}/share/postfix ${PREFIX}/libexec/postfix
	-${RM} -f ${WRKSRC}/conf/*.orig
.if defined(POSTFIX_USE_SASL_AUTH) && ${POSTFIX_USE_SASL_AUTH} == "YES"
	echo "pwcheck_method: sasldb" > ${WRKDIR}/smtpd.conf
	${INSTALL_DATA} ${WRKDIR}/smtpd.conf ${PREFIX}/lib/sasl
	echo lib/sasl/smtpd.conf > ${WRKDIR}/PLIST.sasl
.endif

post-install:
	${INSTALL_DATA} ${WRKDIR}/mailer.conf.postfix ${PREFIX}/etc
	${LN} -sf ${PREFIX}/share/postfix/postfix-script /etc/postfix
	${INSTALL_DATA_DIR} ${POSTFIX_SPOOL}
	${CHMOD} 755 ${POSTFIX_SPOOL}
	${TEST} -f /etc/postfix/main.cf || \
		${INSTALL_DATA} ${PREFIX}/share/postfix/main.cf /etc/postfix
	${TEST} -f /etc/postfix/master.cf || \
		${INSTALL_DATA} ${PREFIX}/share/postfix/master.cf /etc/postfix

.include "../../mk/bsd.pkg.mk"
