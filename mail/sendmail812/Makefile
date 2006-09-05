# $NetBSD: Makefile,v 1.13 2006/09/05 20:06:06 tv Exp $

.include "options.mk"
.include "../../mail/sendmail812/Makefile.common"

PKGNAME=	sendmail-${DIST_VERS}
PKGREVISION=	4
COMMENT=	The well known Mail Transport Agent
HAS_SIG=	yes

CONFLICTS+=	courier-mta-[0-9]* fastforward>=0.51nb2 postfix-[0-9]*

MESSAGE_SRC=	${WRKDIR}/.MESSAGE_SRC
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

PKG_GROUPS=		smmsp
PKG_USERS=		smmsp:smmsp
PKG_GECOS.smmsp=	Sendmail Message Submission Program

post-patch: make-sendmail-siteconfig
.if !empty(PKG_OPTIONS:Mtcpwrappers)
	${CAT} ${FILESDIR}/site.config.m4-tcpwrappers >>${SITECONFIG}
	${ECHO} -n ' TCPWRAPPERS' >>${DESCR_SRC}
.endif
.if !empty(PKG_OPTIONS:Mldap)
	${CAT} ${FILESDIR}/site.config.m4-ldap >>${SITECONFIG}
	${ECHO} -n ' LDAP' >>${DESCR_SRC}
.endif
.if !empty(PKG_OPTIONS:Mdb4)
	${CAT} ${FILESDIR}/site.config.m4-db4 >>${SITECONFIG}
	${ECHO} -n ' DB4' >>${DESCR_SRC}
.elif !empty(PKG_OPTIONS:Mdb2)
	${CAT} ${FILESDIR}/site.config.m4-db2 >>${SITECONFIG}
	${ECHO} -n ' DB2' >>${DESCR_SRC}
.endif
.if !empty(PKG_OPTIONS:Mtls)
	${CAT} ${FILESDIR}/site.config.m4-starttls >>${SITECONFIG}
	${ECHO} -n ' STARTTLS' >>${DESCR_SRC}
.endif
.if !empty(PKG_OPTIONS:Msasl)
	${CAT} ${FILESDIR}/site.config.m4-sasl2 >>${SITECONFIG}
	${ECHO} -n ' SASL2' >>${DESCR_SRC}
.endif
	${ECHO} >>${DESCR_SRC}

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./Build)

post-build:
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	  <${FILESDIR}/mailer.conf >${WRKDIR}/mailer.conf.sendmail
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	${CP} ${PKGDIR}/MESSAGE ${MESSAGE_SRC}
.if !empty(PKG_OPTIONS:Mdb2)
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
	${INSTALL_DATA_DIR} ${PREFIX}/share/sendmail
	${INSTALL_DATA} ${WRKDIR}/mailer.conf.sendmail ${PREFIX}/share/examples/sendmail/mailer.conf
	cd ${WRKSRC}/cf && ${PAX} -rw -pp -pm . ${PREFIX}/share/sendmail
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/sendmail
.if !empty(PKG_OPTIONS:Mdb2)
	${MV} -f /usr/sbin/makemap /usr/sbin/makemap.8.8 || ${TRUE}
.endif
	${INSTALL_DATA} ${WRKSRC}/obj.`uname -srm | ${TR} \  . | ${TR} \/ - | ${SED} s/sun4./sun4/`/libsm/libsm.a \
		${PREFIX}/lib
	${INSTALL_DATA} \
		${WRKSRC}/obj.`uname -srm | ${TR} \  . | ${TR} \/ - | ${SED} s/sun4./sun4/`/libsmutil/libsmutil.a \
		${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"

# has to be below include for bsd.pkg.mk, else substition fails
OBJDIR!=	${ECHO} obj.`uname -srm | ${TR} \  . | ${TR} \/ -`
