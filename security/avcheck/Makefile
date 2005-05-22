# $NetBSD: Makefile,v 1.7 2005/05/22 20:08:29 jlam Exp $

DISTNAME=	avcheck-0.9
CATEGORIES=	security mail
MASTER_SITES=	http://www.corpit.ru/ftp/avcheck/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.corpit.ru/avcheck/
COMMENT=	Mail content filter for SMTP servers

USE_TOOLS+=	gsed

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/avcheck ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/uchroot ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/avcheck.1 ${PREFIX}/man/man1

	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/avcheck
	${INSTALL_DATA} ${WRKSRC}/README.AVP ${PREFIX}/share/doc/avcheck
	${INSTALL_DATA} ${WRKSRC}/README.DrWeb ${PREFIX}/share/doc/avcheck
	${INSTALL_DATA} ${WRKSRC}/README.Exim ${PREFIX}/share/doc/avcheck
	${INSTALL_DATA} ${WRKSRC}/README.Postfix ${PREFIX}/share/doc/avcheck
	${INSTALL_DATA} ${WRKSRC}/README.Sendmail ${PREFIX}/share/doc/avcheck

	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/avcheck
	${INSTALL_DATA} ${WRKSRC}/infected.ex1 \
		${PREFIX}/share/examples/avcheck/infected.ex1
	${INSTALL_DATA} ${WRKSRC}/ex2/template \
		${PREFIX}/share/examples/avcheck/infected.ex2

.include "../../mk/bsd.pkg.mk"
