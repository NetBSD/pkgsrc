# $NetBSD: Makefile,v 1.5 2008/03/04 06:59:04 jlam Exp $
#

DISTNAME=	fillets-ng-data-0.7.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fillets/}

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://fillets.sourceforge.net/
COMMENT=	Fish Fillets NG data files

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes
NO_CONFIGURE=	yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/games/fillets-ng
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/fillets-ng
	cd ${WRKSRC} && \
		${PAX} -rw -pm font images music script sound \
			${DESTDIR}${PREFIX}/share/games/fillets-ng/
	cd ${WRKSRC}/doc/html && \
		${PAX} -rw -pm . ${DESTDIR}${PREFIX}/share/doc/fillets-ng/

.include "../../mk/bsd.pkg.mk"
