# $NetBSD: Makefile,v 1.16 2021/01/16 13:04:42 triaxx Exp $

DISTNAME=	esip-1.0.39
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/esip/
COMMENT=	ProcessOne SIP server component in Erlang
LICENSE=	apache-2.0

DEPENDS+=	erlang-stun>=1.0.40:../../net/erlang-stun
DEPENDS+=	erlang-fast_tls>=1.1.10:../../security/erlang-fast_tls
DEPENDS+=	erlang-p1_utils>=1.0.21:../../misc/erlang-p1_utils

GITHUB_PROJECT=	esip

GNU_CONFIGURE=	yes

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
