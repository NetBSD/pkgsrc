# $NetBSD: Makefile,v 1.13 2000/08/18 22:46:43 hubertf Exp $
# FreeBSD Id: Makefile,v 1.13 1997/04/30 03:18:06 asami Exp
#

DISTNAME=		ls
PKGNAME=		colorls-2.2
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

MANCOMPRESSED_IF_MANZ=	yes

pre-patch:
	${CP} ${WRKSRC}/ls.1 ${WRKSRC}/colorls.1

.include "../../mk/bsd.pkg.mk"
