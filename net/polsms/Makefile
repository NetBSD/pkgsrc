# $NetBSD: Makefile,v 1.11 2003/03/29 12:42:02 jmmv Exp $
#

DISTNAME=	sms-1.9.1h
PKGNAME=	pol${DISTNAME}
WRKSRC=		${WRKDIR}/sms
CATEGORIES=	net
MASTER_SITES=	http://www.ceti.pl/~miki/komputery/download/sms/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.ceti.pl/~miki/komputery/sms.html
COMMENT=	send SMS to cellular phones in Poland (Plus, Idea, Era)

USE_BUILDLINK2=	YES
USE_GMAKE=	YES

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

.include "../../databases/gdbm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
