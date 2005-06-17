# $NetBSD: Makefile,v 1.22 2005/06/17 03:50:27 jlam Exp $
#

DISTNAME=	sms-2.0.2
PKGNAME=	pol${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://www.ceti.pl/~miki/komputery/download/sms/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.ceti.pl/~miki/komputery/sms.html
COMMENT=	Send SMS to cellular phones in Poland (Plus, Idea, Era)

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sms ${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/sms ${PREFIX}/bin/smsaddr
	${INSTALL_DATA_DIR} ${PREFIX}/share/sms
	${INSTALL_DATA_DIR} ${PREFIX}/share/sms/doc
	${INSTALL_DATA_DIR} ${PREFIX}/share/sms/contrib
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/sms/doc
	${INSTALL_DATA} ${WRKSRC}/README.smsrc ${PREFIX}/share/sms/doc
	${INSTALL_DATA} ${WRKSRC}/doc/readme.html ${PREFIX}/share/sms/doc
	${INSTALL_DATA} ${WRKSRC}/contrib/mimecut ${PREFIX}/share/sms/contrib
	${INSTALL_DATA} ${WRKSRC}/contrib/procmailrc ${PREFIX}/share/sms/contrib

.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/pcre++/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
