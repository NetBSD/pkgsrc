# $NetBSD: Makefile,v 1.5.2.1 2005/01/17 20:39:18 snj Exp $
#

DISTNAME=	nbitools-R6.3
PKGNAME=	nbitools-6.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.kitebird.com/imake-book/
COMMENT=	imake and tools derived from NetBSD-current/xsrc

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes

BUILD_TARGET=	World
MAKE_ENV+=	GCCCMD=gcc

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
USE_GNU_TOOLS+=	make
.endif

post-patch:
	@${MV} ${WRKSRC}/config/cf/site.def ${WRKSRC}/config/cf/site.def.orig
	@${SED} -e 's|^\(\#define[ \t]*ProjectRoot\).*|\1 ${PREFIX}|' \
		${WRKSRC}/config/cf/site.def.orig > ${WRKSRC}/config/cf/site.def

.include "../../mk/bsd.pkg.mk"
