# $NetBSD: Makefile,v 1.22 2013/05/31 12:40:01 wiz Exp $
#

DISTNAME=	nbitools-R6.3
PKGNAME=	nbitools-6.3
PKGREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kitebird.com/imake-book/
COMMENT=	Tools and imake derived from NetBSD-current/xsrc

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	destdir
NOT_FOR_UNPRIVILEGED=	yes

BUILD_TARGET=	World
MAKE_ENV+=	GCCCMD=gcc
MAKE_JOBS_SAFE=	NO

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	${IMAKE_TOOLS:Nimake} perl:run

SUBST_CLASSES+=		nbi
SUBST_STAGE.nbi=	pre-configure
SUBST_MESSAGE.nbi=	Fixing definition of ProjectRoot.
SUBST_FILES.nbi=	config/cf/site.def
SUBST_SED.nbi=		-e 's|^\(\#define[ \t]*ProjectRoot\).*|\1 ${PREFIX}|'

post-extract:
	${CP} ${FILESDIR}/DragonFly.cf ${WRKSRC}/config/cf

.include "../../mk/bsd.pkg.mk"
