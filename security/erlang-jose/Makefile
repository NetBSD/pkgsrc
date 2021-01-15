# $NetBSD: Makefile,v 1.3 2021/01/15 23:47:05 triaxx Exp $

DISTNAME=	jose-1.11.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=potatosalad/}
GITHUB_PROJECT=	erlang-jose

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hexdocs.pm/jose/JOSE.html
COMMENT=	JSON Object Signing and Encryption
LICENSE=	mpl-2.0

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake

MAKE_FLAGS+=	SKIP_DEPS=true

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
