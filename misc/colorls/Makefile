# $NetBSD: Makefile,v 1.11 1999/12/07 20:35:55 rh Exp $
# FreeBSD Id: Makefile,v 1.13 1997/04/30 03:18:06 asami Exp
#

DISTNAME=		ls
PKGNAME=		colorls-2.2
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org

MIRROR_DISTFILE=	 no
PATCH_FUZZ_FACTOR=	-F2
MANCOMPRESSED_IF_MANZ=	yes

pre-patch:
	${CP} ${WRKSRC}/ls.1 ${WRKSRC}/colorls.1

.include "../../mk/bsd.pkg.mk"
