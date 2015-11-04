# $NetBSD: Makefile,v 1.1 2015/11/04 13:45:45 fhajny Exp $

DISTNAME=	oauth2-0.6.0.20150928
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=prefiks/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/prefiks/oauth2/
COMMENT=	Erlang Oauth2 implementation
LICENSE=	mit

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar

GITHUB_PROJECT=	oauth2
GITHUB_TAG=	e6da9912e5d8f658e7e868f41a102d085bdbef59
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

NO_CONFIGURE=	yes
USE_TOOLS+=	pax

BUILD_TARGET=	compile

INSTALLATION_DIRS+=	lib/erlang/lib/oauth2

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin \
		${DESTDIR}${PREFIX}/lib/erlang/lib/oauth2/

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
