# $NetBSD: Makefile,v 1.5 1998/04/15 10:38:34 agc Exp $
# FreeBSD Id: Makefile,v 1.13 1997/04/30 03:18:06 asami Exp
#

DISTNAME=	colorls
PKGNAME=	colorls-2.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
DISTFILES=	ls.tar.gz

MAINTAINER=	asami@FreeBSD.ORG

WRKSRC=		${WRKDIR}/ls

MAN1=		colorls.1
CAT1=		colorls.0

pre-patch:
	${CP} ${WRKSRC}/ls.1 ${WRKSRC}/colorls.1

.include "../../mk/bsd.pkg.mk"
