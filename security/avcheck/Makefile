# $NetBSD: Makefile,v 1.15 2013/06/01 12:19:30 shattered Exp $

DISTNAME=	avcheck-0.91
PKGNAME=	avcheck-0.9.1
CATEGORIES=	security mail
MASTER_SITES=	http://www.corpit.ru/ftp/avcheck/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.corpit.ru/avcheck/
COMMENT=	Mail content filter for SMTP servers

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD"
USE_TOOLS+=	gsed
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/avcheck \
			share/examples/avcheck


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/avcheck ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/uchroot ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/avcheck.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

	${INSTALL_DATA} ${WRKSRC}/README.AVP ${DESTDIR}${PREFIX}/share/doc/avcheck
	${INSTALL_DATA} ${WRKSRC}/README.DrWeb ${DESTDIR}${PREFIX}/share/doc/avcheck
	${INSTALL_DATA} ${WRKSRC}/README.Exim ${DESTDIR}${PREFIX}/share/doc/avcheck
	${INSTALL_DATA} ${WRKSRC}/README.Postfix ${DESTDIR}${PREFIX}/share/doc/avcheck
	${INSTALL_DATA} ${WRKSRC}/README.Sendmail ${DESTDIR}${PREFIX}/share/doc/avcheck

	${INSTALL_DATA} ${WRKSRC}/infected.ex1 \
	    ${DESTDIR}${PREFIX}/share/examples/avcheck/infected.ex1
	${INSTALL_DATA} ${WRKSRC}/ex2/template \
	    ${DESTDIR}${PREFIX}/share/examples/avcheck/infected.ex2

.include "../../mk/bsd.pkg.mk"
