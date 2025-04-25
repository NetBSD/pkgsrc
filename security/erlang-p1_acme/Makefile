# $NetBSD: Makefile,v 1.6 2025/04/25 15:35:07 gdt Exp $

DISTNAME=	p1_acme-1.0.25
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}
GITHUB_PROJECT=	p1_acme

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/p1_acme
COMMENT=	Erlang ACME client (RFC8555)
LICENSE=	apache-2.0

# from rebar.config
# erlang < 27 only
DEPENDS+=	erlang-jiffy>=1.1.1:../../textproc/erlang-jiffy
DEPENDS+=	erlang-yconf>=1.0.17:../../textproc/erlang-yconf
DEPENDS+=	erlang-idna>=6.0:../../net/erlang-idna
DEPENDS+=	erlang-base64url>=1.0.1:../../devel/erlang-base64url
DEPENDS+=	erlang-jose>=1.11.10:../../security/erlang-jose

USE_LANGUAGES=	c c++

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
