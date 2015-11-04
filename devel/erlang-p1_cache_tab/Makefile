# $NetBSD: Makefile,v 1.1 2015/11/04 13:45:45 fhajny Exp $

DISTNAME=	p1_cache_tab-0.20150628
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/cache_tab/
COMMENT=	In-memory cache Erlang libraries
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar
DEPENDS+=	erlang-p1_utils-[0-9]*:../../misc/erlang-p1_utils

GITHUB_PROJECT=	cache_tab
GITHUB_TAG=	f7ea12b0ba962a3d2f9a406d2954cf7de4e27230
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

NO_CONFIGURE=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	lib/erlang/lib/p1_cache_tab

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin \
		${DESTDIR}${PREFIX}/lib/erlang/lib/p1_cache_tab/

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
