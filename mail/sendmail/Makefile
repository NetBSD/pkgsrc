# $NetBSD: Makefile,v 1.11 2000/01/02 17:46:47 itojun Exp $

DISTNAME=	sendmail.8.9.3
PKGNAME=	sendmail-8.9.3
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.sendmail.org/pub/sendmail/ \
		ftp://ftp.cert.dfn.de/pub/tools/net/sendmail/ \
		ftp://ftp.kyoto.wide.ad.jp/pub/mail/sendmail/

PATCH_SITES=	ftp://ftp.kyoto.wide.ad.jp/pub/mail/sendmail/
PATCHFILES=	sendmail893+3.2W.patch.gz
PATCH_DIST_ARGS=-d ${WRKSRC}/src -E ${PATCH_DIST_STRIP}
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
OBJDIR!=	echo obj.`uname -srm | tr \  .`
WRKSRC=		${WRKDIR}/${PKGNAME}

BUILD_DEFS+=    USE_INET6

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == YES
MAKE_ENV+=	CONFIG="-f ${WRKSRC}/site.config-v6"
.endif

USE_DB2?=	NO

.if ${USE_DB2} == YES
DEPENDS+=	db-2.7.7:../../databases/db

MAKE_ENV+=	DB_ENVDEF="-I${LOCALBASE}/include/db2" \
		DB_LIBS="-L${LOCALBASE}/lib -ldb2"
PLIST_SRC=	${WRKDIR}/PLIST
.else
MAKE_ENV+=	DB_ENVDEF="" DB_LIBS=""
.endif

post-patch:
.if defined(USE_INET6) && ${USE_INET6} == YES
	@(cp ${FILESDIR}/site.config-v6 ${WRKSRC})
.endif

post-build:
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	  <${FILESDIR}/mailer.conf >${WRKDIR}/mailer.conf.sendmail
	${SED} -e 's#@@PKGNAME@@#${PKGNAME}#g' \
	  -e 's#@@PREFIX@@#${PREFIX}#g' \
	  <${PKGDIR}/MESSAGE >${MESSAGE_FILE}
.if ${USE_DB2} == YES
	${ECHO} >>${MESSAGE_FILE} ""
	${ECHO} >>${MESSAGE_FILE} "If you are upgrading from \"sendmail\" 8.8.x don't forget to rebuild all"
	${ECHO} >>${MESSAGE_FILE} "databases with \"${PREFIX}/bin/newaliases\" and \"${PREFIX}/sbin/makemap\"."
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
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
