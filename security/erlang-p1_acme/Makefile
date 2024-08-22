# $NetBSD: Makefile,v 1.4 2024/08/22 06:05:32 adam Exp $

DISTNAME=	p1_acme-1.0.23
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}
GITHUB_PROJECT=	p1_acme

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/p1_acme
COMMENT=	Erlang ACME client (RFC8555)
LICENSE=	apache-2.0

DEPENDS+=	erlang-base64url>=1.0.1:../../devel/erlang-base64url
DEPENDS+=	erlang-idna>=6.0.0:../../net/erlang-idna
DEPENDS+=	erlang-jiffy>=1.1.1:../../textproc/erlang-jiffy
DEPENDS+=	erlang-jose>=1.11.5:../../security/erlang-jose
DEPENDS+=	erlang-yconf>=1.0.16:../../textproc/erlang-yconf

USE_LANGUAGES=	c c++

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
