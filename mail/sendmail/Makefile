# $NetBSD: Makefile,v 1.69 2004/04/21 21:09:31 cube Exp $

.include "../../mail/sendmail/Makefile.common"

PKGNAME=	sendmail-${DIST_VERS}
COMMENT=	The well known Mail Transport Agent

CONFLICTS+=	postfix-[0-9]*

MESSAGE_SRC=	${WRKDIR}/.MESSAGE_SRC
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

.if ${OPSYS} == "SunOS"
USE_DB2?=	YES
.else
USE_DB2?=	NO
.endif
.if defined(USE_DB4) && ${USE_DB4} == YES
.include "../../databases/db4/buildlink2.mk"
.elif ${USE_DB2} == YES
.include "../../databases/db/buildlink2.mk"
.endif

.if defined(USE_OPENLDAP) && ${USE_OPENLDAP} == YES
.include "../../databases/openldap/buildlink2.mk"
.endif

.if defined(USE_SASL2) && ${USE_SASL2} == YES
.include "../../security/cyrus-sasl2/buildlink2.mk"
.elif defined(USE_SASL) && ${USE_SASL} == YES
.include "../../security/cyrus-sasl/buildlink2.mk"
.endif

.if defined(USE_STARTTLS) && ${USE_STARTTLS} == YES
.include "../../security/openssl/buildlink2.mk"
.endif

USE_TCPWRAPPERS?=	YES
.if ${USE_TCPWRAPPERS} == YES
.include "../../security/tcp_wrappers/buildlink2.mk"
.endif

post-patch: make-sendmail-siteconfig
.if ${USE_TCPWRAPPERS} == YES
	${CAT} ${FILESDIR}/site.config.m4-tcpwrappers >>${SITECONFIG}
	${ECHO} -n ' TCPWRAPPERS' >>${DESCR_SRC}
.endif
.if defined(USE_OPENLDAP) && ${USE_OPENLDAP} == YES
	${CAT} ${FILESDIR}/site.config.m4-ldap >>${SITECONFIG}
	${ECHO} -n ' LDAP' >>${DESCR_SRC}
.endif
.if defined(USE_DB4) && ${USE_DB4} == YES
	${CAT} ${FILESDIR}/site.config.m4-db4 >>${SITECONFIG}
	${ECHO} -n ' DB4' >>${DESCR_SRC}
.elif ${USE_DB2} == YES
	${CAT} ${FILESDIR}/site.config.m4-db2 >>${SITECONFIG}
	${ECHO} -n ' DB2' >>${DESCR_SRC}
.endif
.if defined(USE_STARTTLS) && ${USE_STARTTLS} == YES
	${CAT} ${FILESDIR}/site.config.m4-starttls >>${SITECONFIG}
	${ECHO} -n ' STARTTLS' >>${DESCR_SRC}
.endif
.if defined(USE_SASL2) && ${USE_SASL2} == YES
	${CAT} ${FILESDIR}/site.config.m4-sasl2 >>${SITECONFIG}
	${ECHO} -n ' SASL2' >>${DESCR_SRC}
.elif defined(USE_SASL) && ${USE_SASL} == YES
	${CAT} ${FILESDIR}/site.config.m4-sasl >>${SITECONFIG}
	${ECHO} -n ' SASL' >>${DESCR_SRC}
.endif
	${ECHO} >>${DESCR_SRC}

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./Build)

post-build:
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	  <${FILESDIR}/mailer.conf >${WRKDIR}/mailer.conf.sendmail
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	${CP} ${PKGDIR}/MESSAGE ${MESSAGE_SRC}
.if ${USE_DB2} == YES
	${ECHO} "" >>${MESSAGE_SRC}
	${ECHO} "If you are upgrading from \"sendmail\" 8.8.x don't forget to rebuild all" >>${MESSAGE_SRC}
	${ECHO} "databases with \"${PREFIX}/bin/newaliases\" and \"${PREFIX}/sbin/makemap\"." >>${MESSAGE_SRC}
	${ECHO} >>${PLIST_SRC} "@exec mv -f /usr/sbin/makemap /usr/sbin/makemap.8.8 || true"
	${ECHO} >>${PLIST_SRC} "@unexec mv -f /usr/sbin/makemap.8.8 /usr/sbin/makemap || true"
.endif

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/sendmail

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/sendmail
	${INSTALL_DATA} ${WRKDIR}/mailer.conf.sendmail ${PREFIX}/share/examples/sendmail/mailer.conf
	${CP} -pr ${WRKSRC}/cf ${PREFIX}/share/sendmail
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/sendmail
.if ${USE_DB2} == YES
	${MV} -f /usr/sbin/makemap /usr/sbin/makemap.8.8 || ${TRUE}
.endif
	${INSTALL_DATA} ${WRKSRC}/obj.`uname -srm | ${TR} \  . | ${TR} \/ - | ${SED} s/sun4./sun4/`/libsm/libsm.a \
		${PREFIX}/lib
	${INSTALL_DATA} \
		${WRKSRC}/obj.`uname -srm | ${TR} \  . | ${TR} \/ - | ${SED} s/sun4./sun4/`/libsmutil/libsmutil.a \
		${PREFIX}/lib

USE_PKGINSTALL=	yes
PKG_GROUPS=	smmsp
PKG_USERS=	smmsp:smmsp::Sendmail\\ Message\\ Submission\\ Program

.include "../../mk/bsd.pkg.mk"

# has to be below include for bsd.pkg.mk, else substition fails
OBJDIR!=	${ECHO} obj.`uname -srm | ${TR} \  . | ${TR} \/ -`
