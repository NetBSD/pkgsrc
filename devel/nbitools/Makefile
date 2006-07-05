# $NetBSD: Makefile,v 1.12 2006/07/05 04:59:47 jlam Exp $
#

DISTNAME=	nbitools-R6.3
PKGNAME=	nbitools-6.3
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.kitebird.com/imake-book/
COMMENT=	imake and tools derived from NetBSD-current/xsrc

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_TARGET=	World
MAKE_ENV+=	GCCCMD=gcc

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	${IMAKE_TOOLS:Nimake}

SUBST_CLASSES+=		nbi
SUBST_STAGE.nbi=	pre-configure
SUBST_MESSAGE.nbi=	Fixing definition of ProjectRoot.
SUBST_FILES.nbi=	config/cf/site.def
SUBST_SED.nbi=		-e 's|^\(\#define[ \t]*ProjectRoot\).*|\1 ${PREFIX}|'

post-extract:
	${CP} ${FILESDIR}/DragonFly.cf ${WRKSRC}/config/cf

.include "../../mk/bsd.pkg.mk"
