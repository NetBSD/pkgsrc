# $NetBSD: Makefile,v 1.19 2021/05/21 07:49:52 triaxx Exp $

DISTNAME=	fast_tls-1.1.12
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/tls/
COMMENT=	TLS / SSL OpenSSL-based native driver for Erlang / Elixir
LICENSE=	apache-2.0

GITHUB_PROJECT=	fast_tls

DEPENDS+=	erlang-p1_utils>=1.0.22:../../misc/erlang-p1_utils

GNU_CONFIGURE=	yes

MAKE_ENV+=	REBAR=${REBAR}

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
