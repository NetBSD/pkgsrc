# $NetBSD: Makefile,v 1.11 2020/01/18 23:32:00 rillig Exp $
#

DISTNAME=	fillets-ng-data-1.0.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fillets/}

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	https://fillets.sourceforge.net/
COMMENT=	Fish Fillets NG data files
LICENSE=	gnu-gpl-v2

NO_BUILD=	yes
NO_CONFIGURE=	yes
USE_TOOLS+=	pax

FIND_EXCLUDE=	\( -name \*.orig \)

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/games/fillets-ng
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/fillets-ng
	cd ${WRKSRC} && \
	cd ${WRKSRC} && ${FIND} font images music script sound \
	    -type f -and \! ${FIND_EXCLUDE} -print | \
	    pax -rw -pm  ${DESTDIR}${PREFIX}/share/games/fillets-ng/
	cd ${WRKSRC}/doc/html && ${FIND} . -type f -and \! ${FIND_EXCLUDE} \
	    -print | pax -rw -pp -pm ${DESTDIR}${PREFIX}/share/doc/fillets-ng/

.include "../../mk/bsd.pkg.mk"
