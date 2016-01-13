# $NetBSD: Makefile,v 1.2 2016/01/13 15:16:02 fhajny Exp $

DISTNAME=	cache_tab-1.0.1
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
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

NO_CONFIGURE=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	lib/erlang/lib/cache_tab

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin \
		${DESTDIR}${PREFIX}/lib/erlang/lib/cache_tab/

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
