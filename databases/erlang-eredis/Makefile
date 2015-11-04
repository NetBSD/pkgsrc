# $NetBSD: Makefile,v 1.1 2015/11/04 13:45:44 fhajny Exp $

DISTNAME=	eredis-1.0.8.20150910
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=wooga/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/wooga/eredis/
COMMENT=	Erlang Redis client
LICENSE=	mit

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar

GITHUB_PROJECT=	eredis
GITHUB_TAG=	bf12ecb30253c84a2331f4f0d93fd68856fcb9f4
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake pax

INSTALLATION_DIRS+=	lib/erlang/lib/eredis

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin include \
		${DESTDIR}${PREFIX}/lib/erlang/lib/eredis/

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
