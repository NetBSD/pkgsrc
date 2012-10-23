# $NetBSD: Makefile,v 1.2 2012/10/23 17:19:10 asau Exp $
#

DISTNAME=	sslh-1.7a
CATEGORIES=	net
MASTER_SITES=	http://www.rutschle.net/tech/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rutschle.net/tech/sslh.shtml
COMMENT=	Multiplex ssl and ssh connections on the same port
LICENSE=	gnu-gpl-v2

USE_TOOLS=	gmake pod2man
USE_LANGUAGES=	c

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sslh ${DESTDIR}${PREFIX}/sbin/.
	${INSTALL_MAN} ${WRKSRC}/sslh.8.gz \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/.

.include "../../mk/bsd.pkg.mk"
