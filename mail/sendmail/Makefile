# $NetBSD: Makefile,v 1.2 1999/04/10 16:41:21 tron Exp $

DISTNAME=	sendmail.8.9.3
PKGNAME=	sendmail-8.9.3
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.sendmail.org/pub/sendmail/ \
		ftp://ftp.cert.dfn.de/pub/tools/net/sendmail/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.sendmail.org/

DEPENDS+=	db-2.7.3:../../databases/db

LICENSE=	no-profit

NO_CONFIGURE=	yes
MAKE_ENV+=	MANOWN="${MANOWN}" MANGRP="${MANGRP}" MANMODE="${MANMODE}"

MESSAGE_FILE=	${WRKDIR}/MESSAGE
WRKSRC=		${WRKDIR}/${PKGNAME}
OBJDIR!=	echo obj.`uname -srm | tr \  .`

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

.include "../../mk/bsd.pkg.mk"
