# $NetBSD: Makefile,v 1.7 1998/05/21 14:06:37 frueauf Exp $
# FreeBSD Id: Makefile,v 1.13 1997/04/30 03:18:06 asami Exp
#

DISTNAME=	colorls
PKGNAME=	colorls-2.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
DISTFILES=	ls.tar.gz

MAINTAINER=	packages@netbsd.org

WRKSRC=		${WRKDIR}/ls

# Do not list MAN/CAT pages here. It will confuse if MANZ is set.
# The pkg uses BSD-style-Makefiles itself, so it does the right thing.

pre-patch:
	${CP} ${WRKSRC}/ls.1 ${WRKSRC}/colorls.1

.include "../../mk/bsd.pkg.mk"
