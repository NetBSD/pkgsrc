# $NetBSD: Makefile,v 1.2 2004/11/27 16:12:27 salo Exp $
#

DISTNAME=	fillets-ng-data-0.6.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fillets/}

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://fillets.sf.net/
COMMENT=	Fish Fillets NG data files

NO_BUILD=	yes
NO_CONFIGURE=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/games/fillets-ng
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/fillets-ng
	cd ${WRKSRC} && \
		${PAX} -rw -pm font images music script sound \
			${PREFIX}/share/games/fillets-ng/
	cd ${WRKSRC}/doc/html/ && \
		${PAX} -rw -pm . ${PREFIX}/share/doc/html/fillets-ng/

.include "../../mk/bsd.pkg.mk"
