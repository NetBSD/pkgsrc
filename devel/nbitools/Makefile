# $NetBSD: Makefile,v 1.1.1.1.2.2 2002/06/23 18:44:36 jlam Exp $
#

DISTNAME=	nbitools-R6.3
PKGNAME=	nbitools-6.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.kitebird.com/imake-book/
COMMENT=	imake and tools derived from NetBSD-current/xsrc

ALL_TARGET=	World
MAKE_ENV+=	GCCCMD=gcc

post-patch:
	@${MV} ${WRKSRC}/config/cf/site.def ${WRKSRC}/config/cf/site.def.orig
	@${SED} -e 's|^\(\#define[ \t]*ProjectRoot\).*|\1 ${PREFIX}|' \
		${WRKSRC}/config/cf/site.def.orig > ${WRKSRC}/config/cf/site.def

.include "../../mk/bsd.pkg.mk"
