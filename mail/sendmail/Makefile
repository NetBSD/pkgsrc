# $NetBSD: Makefile,v 1.25 2000/11/19 07:44:38 taca Exp $

DISTNAME=	sendmail.8.11.1
PKGNAME=	sendmail-8.11.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.sendmail.org/pub/sendmail/ \
		ftp://ftp.cert.dfn.de/pub/tools/net/sendmail/ \
		ftp://ftp.kyoto.wide.ad.jp/pub/mail/sendmail/

PATCH_SITES=	ftp://ftp.kyoto.wide.ad.jp/pub/mail/smtpfeed/
PATCHFILES=	sendmail8.11.1+3.4W.patch.gz
PATCH_DIST_ARGS=-d ${WRKSRC}/sendmail -E ${PATCH_DIST_STRIP}
.if !(defined(PATCH_DEBUG) || defined(PKG_VERBOSE))
PATCH_DIST_ARGS+=--forward --quiet
.endif

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.sendmail.org/

LICENSE=	no-profit

NO_CONFIGURE=	yes
MAKE_ENV+=	BSD_BINOWN="${BINOWN}" BSD_BINGRP="${BINGRP}" \
		BSD_MANOWN="${MANOWN}" BSD_MANGRP="${MANGRP}"

MESSAGE_FILE=	${WRKDIR}/MESSAGE
WRKSRC=		${WRKDIR}/${PKGNAME}
SITECONFIG=	${WRKSRC}/devtools/Site/site.config.m4

BUILD_DEFS+=    USE_INET6

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
USE_DB2?=	YES
.else
USE_DB2?=	NO
.endif

PLIST_SRC=	${WRKDIR}/.PLIST_SRC
DESCR_SRC=	${WRKDIR}/.DESCR_SRC

.if defined(USE_LDAP) && ${USE_LDAP} == YES
DEPENDS+=	openldap-1.2.*:../../databases/openldap
.endif
.if ${USE_DB2} == YES
DEPENDS+=	db-2.7.7:../../databases/db
.endif
.if defined(USE_STARTTLS) && ${USE_STARTTLS} == YES
USE_SSL=	yes
.endif

post-patch:
	${CP} ${FILESDIR}/site.config.m4 ${SITECONFIG}
	${CHMOD} +w ${SITECONFIG}
	${CP} ${PKGDIR}/DESCR ${DESCR_SRC}
	${ECHO} '---' >> ${DESCR_SRC}
	${ECHO} -n 'compiled features:' >> ${DESCR_SRC}
	${ECHO} -n ' WIDE' >> ${DESCR_SRC}
.if defined(USE_INET6) && ${USE_INET6} == YES
	${CAT} ${FILESDIR}/site.config.m4-v6 >> ${SITECONFIG}
	${ECHO} -n ' INET6' >> ${DESCR_SRC}
.endif
.if ${OPSYS} == "NetBSD"
	${CAT} ${FILESDIR}/site.config.m4-tcpwrappers >> ${SITECONFIG}
	${ECHO} -n ' TCPWRAPPERS' >> ${DESCR_SRC}
.endif
.if defined(USE_LDAP) && ${USE_LDAP} == YES
	${CAT} ${FILESDIR}/site.config.m4-ldap >> ${SITECONFIG}
	${ECHO} -n ' LDAP' >> ${DESCR_SRC}
.endif
.if ${USE_DB2} == YES
	${CAT} ${FILESDIR}/site.config.m4-db2 >> ${SITECONFIG}
	${ECHO} -n ' DB2' >> ${DESCR_SRC}
.endif
.if defined(USE_STARTTLS) && ${USE_STARTTLS} == YES
	${CAT} ${FILESDIR}/site.config.m4-starttls >> ${SITECONFIG}
	${ECHO} -n ' STARTTLS' >> ${DESCR_SRC}
.endif
	${ECHO} >> ${DESCR_SRC}

do-build:
	@(cd ${WRKSRC}; ./Build)

post-build:
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	  <${FILESDIR}/mailer.conf >${WRKDIR}/mailer.conf.sendmail
	${SED} -e 's#@@PKGNAME@@#${PKGNAME}#g' \
	  -e 's#@@PREFIX@@#${PREFIX}#g' \
	  <${PKGDIR}/MESSAGE >${MESSAGE_FILE}
	${CAT} ${PKGDIR}/PLIST.common ${PKGDIR}/PLIST.${LOWER_OPSYS} > ${PLIST_SRC}
.if ${USE_DB2} == YES
	${ECHO} >>${MESSAGE_FILE} ""
	${ECHO} >>${MESSAGE_FILE} "If you are upgrading from \"sendmail\" 8.8.x don't forget to rebuild all"
	${ECHO} >>${MESSAGE_FILE} "databases with \"${PREFIX}/bin/newaliases\" and \"${PREFIX}/sbin/makemap\"."
	${ECHO} >>${PLIST_SRC} "@exec mv -f /usr/sbin/makemap /usr/sbin/makemap.8.8 || true"
	${ECHO} >>${PLIST_SRC} "@unexec mv -f /usr/sbin/makemap.8.8 /usr/sbin/makemap || true"
.endif

pre-install:
	${MKDIR} ${PREFIX}/libexec/sendmail

post-install:
	${INSTALL_DATA} ${WRKDIR}/mailer.conf.sendmail ${PREFIX}/etc
	${CP} -pr ${WRKSRC}/cf ${PREFIX}/share/sendmail
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/sendmail
.if ${USE_DB2} == YES
	${MV} -f /usr/sbin/makemap /usr/sbin/makemap.8.8 || ${TRUE}
.endif

.include "../../mk/bsd.pkg.mk"

# has to be below include for bsd.pkg.mk, else substition fails
OBJDIR!=	${ECHO} obj.`uname -srm | ${TR} \  .`
