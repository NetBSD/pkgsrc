# $NetBSD: Makefile,v 1.8 2017/07/30 22:32:21 wiz Exp $

DISTNAME=	fast_tls-1.0.13
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/tls/
COMMENT=	TLS / SSL OpenSSL-based native driver for Erlang / Elixir
LICENSE=	apache-2.0

GITHUB_PROJECT=	fast_tls

DEPENDS+=	erlang-p1_utils>=1.0.9:../../misc/erlang-p1_utils

GNU_CONFIGURE=	yes

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
