# $NetBSD: Makefile,v 1.17 2004/04/21 21:09:31 cube Exp $

DISTNAME=	sendmail.8.11.6
PKGNAME=	sendmail-8.11.6
PKGREVISION=	7
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.sendmail.org/pub/sendmail/ \
		ftp://ftp.fu-berlin.de/unix/mail/sendmail/ \
		ftp://ftp.kyoto.wide.ad.jp/pub/mail/sendmail/

USE_WIDEPATCH?=	YES
.if ${USE_WIDEPATCH} == "YES"
PATCH_SITES=	ftp://ftp.kyoto.wide.ad.jp/pub/mail/smtpfeed/
PATCHFILES=	sendmail8.11.6+3.4W.patch.gz
PATCH_DIST_ARGS=-d ${WRKSRC}/sendmail -E ${PATCH_DIST_STRIP}
.if !(defined(PATCH_DEBUG) || defined(PKG_VERBOSE))
PATCH_DIST_ARGS+=--forward --quiet
.endif
PATCH_DIST_STRIP=	-p1
.endif

CR_PATCH=sendmail.8.11.6.security.cr.patch
PATCHFILES+=	${CR_PATCH}
SITES_${CR_PATCH}=	${MASTER_SITES}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.sendmail.org/
COMMENT=	The well known Mail Transport Agent

CONFLICTS+=	postfix-[0-9]*

LICENSE=	no-profit

WRKSRC=		${WRKDIR}/${PKGNAME:C/nb[0-9]+$//}
USE_BUILDLINK3=	yes
MAKE_ENV+=	BSD_BINOWN="${BINOWN}" BSD_BINGRP="${BINGRP}" \
		BSD_MANOWN="${MANOWN}" BSD_MANGRP="${MANGRP}" \
		BUILDLINK_DIR="${BUILDLINK_DIR}"
SITECONFIG=	${WRKSRC}/devtools/Site/site.config.m4

BUILD_DEFS+=    USE_WIDEPATCH USE_INET6 USE_TCPWRAPPERS USE_OPENLDAP USE_DB2 \
		USE_SASL USE_STARTTLS
MESSAGE_SRC=	${WRKDIR}/.MESSAGE_SRC
PLIST_SRC=	${WRKDIR}/.PLIST_SRC
DESCR_SRC=	${WRKDIR}/.DESCR_SRC

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
USE_DB2?=	YES
.else
USE_DB2?=	NO
.endif
.if ${USE_DB2} == "YES"
.  include "../../databases/db/buildlink3.mk"
.endif

.if defined(USE_OPENLDAP) && (${USE_OPENLDAP} == "YES")
.  include "../../databases/openldap/buildlink3.mk"
.endif

.if defined(USE_SASL) && (${USE_SASL} == "YES")
.  include "../../security/cyrus-sasl/buildlink3.mk"
.endif

.if defined(USE_STARTTLS) && (${USE_STARTTLS} == "YES")
.  include "../../security/openssl/buildlink3.mk"
.endif

USE_TCPWRAPPERS?=	YES
.if ${USE_TCPWRAPPERS} == "YES"
.  include "../../security/tcp_wrappers/buildlink3.mk"
.endif

post-patch:
	${CP} ${FILESDIR}/site.config.m4 ${SITECONFIG}
	${CHMOD} +w ${SITECONFIG}
	${CP} ${PKGDIR}/DESCR ${DESCR_SRC}
	${ECHO} '---' >>${DESCR_SRC}
	${ECHO} -n 'compiled features:' >>${DESCR_SRC}
.if ${USE_WIDEPATCH} == YES
	${ECHO} -n ' WIDE' >>${DESCR_SRC}
.endif
.if defined(USE_INET6) && ${USE_INET6} == YES
	${CAT} ${FILESDIR}/site.config.m4-v6 >>${SITECONFIG}
	${ECHO} -n ' INET6' >>${DESCR_SRC}
.endif
.if ${USE_TCPWRAPPERS} == YES
	${CAT} ${FILESDIR}/site.config.m4-tcpwrappers >>${SITECONFIG}
	${ECHO} -n ' TCPWRAPPERS' >>${DESCR_SRC}
.endif
.if ${OPSYS} == "SunOS"
	${CAT} ${FILESDIR}/site.config.m4-solaris >>${SITECONFIG}
.endif
.if defined(USE_OPENLDAP) && ${USE_OPENLDAP} == YES
	${CAT} ${FILESDIR}/site.config.m4-ldap >>${SITECONFIG}
	${ECHO} -n ' LDAP' >>${DESCR_SRC}
.endif
.if ${USE_DB2} == YES
	${CAT} ${FILESDIR}/site.config.m4-db2 >>${SITECONFIG}
	${ECHO} -n ' DB2' >>${DESCR_SRC}
.endif
.if defined(USE_STARTTLS) && ${USE_STARTTLS} == YES
	${CAT} ${FILESDIR}/site.config.m4-starttls >>${SITECONFIG}
	${ECHO} -n ' STARTTLS' >>${DESCR_SRC}
.endif
.if defined(USE_SASL) && ${USE_SASL} == YES
	${CAT} ${FILESDIR}/site.config.m4-sasl >>${SITECONFIG}
	${ECHO} -n ' SASL' >>${DESCR_SRC}
.endif
	${ECHO} >>${DESCR_SRC}

do-build:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./Build

post-build:
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	  <${FILESDIR}/mailer.conf >${WRKDIR}/mailer.conf.sendmail
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	${CP} ${PKGDIR}/MESSAGE ${MESSAGE_SRC}
.if ${USE_DB2} == "YES"
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
.if ${USE_DB2} == "YES"
	${MV} -f /usr/sbin/makemap /usr/sbin/makemap.8.8 || ${TRUE}
.endif

.include "../../mk/bsd.pkg.mk"

# has to be below include for bsd.pkg.mk, else substition fails
OBJDIR!=	${ECHO} obj.`${UNAME} -srm | ${TR} \  .`
