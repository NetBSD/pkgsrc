# $NetBSD: Makefile,v 1.1 2021/01/16 19:47:57 triaxx Exp $

DISTNAME=	p1_acme-1.0.10
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/p1_acme
COMMENT=	Erlang ACME client (RFC8555)
LICENSE=	apache-2.0

DEPENDS+=	erlang-base64url>=1.0:../../devel/erlang-base64url
DEPENDS+=	erlang-idna>=6.0.0:../../net/erlang-idna
DEPENDS+=	erlang-jiffy>=1.0.5:../../textproc/erlang-jiffy
DEPENDS+=	erlang-jose>=1.9.0:../../security/erlang-jose
DEPENDS+=	erlang-yconf>=1.0.9:../../textproc/erlang-yconf

USE_LANGUAGES=	c c++

GITHUB_PROJECT=	p1_acme

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
