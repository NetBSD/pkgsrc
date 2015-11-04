# $NetBSD: Makefile,v 1.1 2015/11/04 13:45:45 fhajny Exp $

DISTNAME=	p1_zlib-0.20150223
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/zlib/
COMMENT=	Native zlib driver for Erlang
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar

GITHUB_PROJECT=	zlib
GITHUB_TAG=	e3d4222b7aae616d7ef2e7e2fa0bbf451516c602
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

GNU_CONFIGURE=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	lib/erlang/lib/p1_zlib

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin priv \
		${DESTDIR}${PREFIX}/lib/erlang/lib/p1_zlib/

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
