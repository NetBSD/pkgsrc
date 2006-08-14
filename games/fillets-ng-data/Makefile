# $NetBSD: Makefile,v 1.3 2006/08/14 22:33:59 wiz Exp $
#

DISTNAME=	fillets-ng-data-0.7.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fillets/}

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://fillets.sf.net/
COMMENT=	Fish Fillets NG data files

NO_BUILD=	yes
NO_CONFIGURE=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/games/fillets-ng
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fillets-ng
	cd ${WRKSRC} && \
		${PAX} -rw -pm font images music script sound \
			${PREFIX}/share/games/fillets-ng/
	cd ${WRKSRC}/doc/html && \
		${PAX} -rw -pm . ${PREFIX}/share/doc/fillets-ng/

.include "../../mk/bsd.pkg.mk"
