# $NetBSD: Makefile,v 1.7 1999/12/01 21:15:20 tron Exp $

DISTNAME=	sendmail.8.9.3
PKGNAME=	sendmail-8.9.3
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.sendmail.org/pub/sendmail/ \
		ftp://ftp.cert.dfn.de/pub/tools/net/sendmail/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.sendmail.org/

LICENSE=	no-profit

NO_CONFIGURE=	yes
MAKE_ENV+=	BSD_BINOWN="${BINOWN}" BSD_BINGRP="${BINGRP}" \
		BSD_MANOWN="${MANOWN}" BSD_MANGRP="${MANGRP}"

MESSAGE_FILE=	${WRKDIR}/MESSAGE
WRKSRC=		${WRKDIR}/${PKGNAME}
OBJDIR!=	echo obj.`uname -srm | tr \  .`

.include "../../mk/bsd.prefs.mk"

.if defined(USE_DB2) && ${USE_DB2} == YES
DEPENDS+=	db-2.7.7:../../databases/db

MAKE_ENV+=	DB_ENVDEF="-I${LOCALBASE}/include/db2" \
		DB_LIBS="-L${LOCALBASE}/lib -ldb2"
.else
MAKE_ENV+=	DB_ENVDEF="" DB_LIBS=""
.endif

post-build:
	${SED} -e 's#@@PKGNAME@@#${PKGNAME}#g' \
	  -e 's#@@PREFIX@@#${PREFIX}#g' \
	  <${PKGDIR}/MESSAGE >${MESSAGE_FILE}
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	  <${FILESDIR}/mailer.conf >${WRKDIR}/mailer.conf.sendmail

pre-install:
	${MKDIR} ${PREFIX}/libexec/sendmail

post-install:
	${INSTALL_DATA} ${WRKDIR}/mailer.conf.sendmail ${PREFIX}/etc
	${CP} -pr ${WRKSRC}/cf ${PREFIX}/share/sendmail
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/sendmail
	${MV} -f /usr/sbin/makemap /usr/sbin/makemap.8.8 || ${TRUE}

.include "../../mk/bsd.pkg.mk"
