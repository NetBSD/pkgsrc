# $NetBSD: Makefile,v 1.2 1999/05/12 06:08:48 sakamoto Exp $
# FreeBSD Id: Makefile,v 1.3 1998/08/13 09:20:41 itojun Exp $

DISTNAME=	snooper.980813
PKGNAME=	snooper-980813
CATEGORIES=	comms
MASTER_SITES=   ftp://ftp.foretune.co.jp/pub/tools/snooper/

MAINTAINER=	itojun@itojun.org

WRKSRC=		${WRKDIR}/snooper/build
GNU_CONFIGURE=	yes

MESSAGE_SRC=	${PKGDIR}/MESSAGE
MESSAGE_FILE=	${WRKDIR}/.MESSAGE

pre-install:
	@${SED} -e 's|$${PREFIX}|${PREFIX}|' ${MESSAGE_SRC} > ${MESSAGE_FILE}

post-install:
	${MKDIR} ${PREFIX}/share/doc/snooper
	${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/snooper

.include "../../mk/bsd.pkg.mk"
