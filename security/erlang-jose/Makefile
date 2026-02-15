# $NetBSD: Makefile,v 1.7 2026/02/15 18:21:05 gdt Exp $

DISTNAME=	jose-1.11.12
PKGREVISION=	1
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

TOOL_DEPENDS+=	elixir>=1.17.0:../../lang/elixir

MAKE_FLAGS+=	SKIP_DEPS=true

# Fails to build if a previous erlang-jose is not installed.
# https://github.com/potatosalad/erlang-jose/issues/189

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
