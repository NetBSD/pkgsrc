# $NetBSD: Makefile,v 1.3 2001/07/09 09:11:27 zuntum Exp $
#

DISTNAME=	sms-1.8.9
PKGNAME=	pol${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://www.ceti.pl/~miki/komputery/download/sms/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.ceti.pl/~miki/komputery/sms.html
COMMENT=	useful command-line interface to sending SMS to Polish GSM networks

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES

WRKSRC=		${WRKDIR}/sms

MAKE_ENV+=	CC="${CXX}" C="${CC}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sms ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/sms ${PREFIX}/bin/smsaddr
	${INSTALL_DATA_DIR} ${PREFIX}/share/sms ${PREFIX}/share/sms/doc	\
		${PREFIX}/share/sms/contrib
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/sms/doc
	cd ${WRKSRC}/doc && ${INSTALL_DATA} old_solaris NetBSD solaris 	\
		plusmail FreeBSD qmail eranet podziel_sms eragsm.asp	\
		${PREFIX}/share/sms/doc
	cd ${WRKSRC}/contrib && ${INSTALL_DATA} mimecut procmailrc	\
		sms.cgi sms.html ${PREFIX}/share/sms/contrib

.include "../../databases/gdbm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
