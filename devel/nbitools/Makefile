# $NetBSD: Makefile,v 1.2 2003/07/17 21:31:55 grant Exp $
#

DISTNAME=	nbitools-R6.3
PKGNAME=	nbitools-6.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.kitebird.com/imake-book/
COMMENT=	imake and tools derived from NetBSD-current/xsrc

ALL_TARGET=	World
MAKE_ENV+=	GCCCMD=gcc

post-patch:
	@${MV} ${WRKSRC}/config/cf/site.def ${WRKSRC}/config/cf/site.def.orig
	@${SED} -e 's|^\(\#define[ \t]*ProjectRoot\).*|\1 ${PREFIX}|' \
		${WRKSRC}/config/cf/site.def.orig > ${WRKSRC}/config/cf/site.def

.include "../../mk/bsd.pkg.mk"
