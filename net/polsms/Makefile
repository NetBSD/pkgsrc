# $NetBSD: Makefile,v 1.15 2004/01/20 12:22:20 agc Exp $
#

DISTNAME=	sms-1.9.2d
PKGNAME=	pol${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://www.ceti.pl/~miki/komputery/download/sms/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.ceti.pl/~miki/komputery/sms.html
COMMENT=	Send SMS to cellular phones in Poland (Plus, Idea, Era)

WRKSRC=		${WRKDIR}/sms
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
