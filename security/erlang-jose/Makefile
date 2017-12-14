# $NetBSD: Makefile,v 1.1 2017/12/14 21:04:40 fhajny Exp $

DISTNAME=	jose-1.8.4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=potatosalad/}

HOMEPAGE=	https://hexdocs.pm/jose/JOSE.html
COMMENT=	JSON Object Signing and Encryption
LICENSE=	mpl-2.0

DEPENDS+=	erlang-base64url-[0-9]*:../../devel/erlang-base64url

GITHUB_PROJECT=	erlang-jose
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake

MAKE_FLAGS+=	SKIP_DEPS=true

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
