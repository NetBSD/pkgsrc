# $NetBSD: Makefile,v 1.1.1.1 1999/04/08 23:00:33 tron Exp $

DISTNAME=	sendmail.8.9.3
PKGNAME=	sendmail-8.9.3
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.sendmail.org/pub/sendmail/ \
		ftp://ftp.cert.dfn.de/pub/tools/net/sendmail/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.sendmail.org/

LICENSE=	no-profit

MESSAGE_FILE=	${WRKDIR}/MESSAGE
NO_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}
OBJDIR!=	echo obj.`uname -srm | tr \  .`

LIBEXECDIR=	${PREFIX}/libexec/sendmail
SBINDIR=	${PREFIX}/sbin

post-build:
	${SED} -e 's#@@PKGNAME@@#${PKGNAME}#g' \
	  -e 's#@@PREFIX@@#${PREFIX}#g' \
	  <${PKGDIR}/MESSAGE >${MESSAGE_FILE}
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	  <${FILESDIR}/mailer.conf >${WRKDIR}/mailer.conf.sendmail

do-install:
	${INSTALL_DATA} ${WRKDIR}/mailer.conf.sendmail ${PREFIX}/etc
	${MKDIR} -p ${LIBEXECDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${OBJDIR}/sendmail ${LIBEXECDIR}
	${CHMOD} u+s ${LIBEXECDIR}/sendmail
.for SECTION in 1 5 8
	${INSTALL_DATA} ${WRKSRC}/src/${OBJDIR}/*.${SECTION} \
	  ${PREFIX}/man/man${SECTION}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/mailstats/${OBJDIR}/mailstats ${SBINDIR}
	${INSTALL_DATA} ${WRKSRC}/mailstats/${OBJDIR}/*.8 ${PREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/praliases/${OBJDIR}/praliases ${SBINDIR}
	${INSTALL_DATA} ${WRKSRC}/praliases/${OBJDIR}/*.8 ${PREFIX}/man/man8
	${CP} -pr ${WRKSRC}/cf ${PREFIX}/share/sendmail
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/sendmail

.include "../../mk/bsd.pkg.mk"
