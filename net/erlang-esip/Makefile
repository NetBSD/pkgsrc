# $NetBSD: Makefile,v 1.19 2025/04/25 11:19:24 gdt Exp $

DISTNAME=	esip-1.0.57
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}
GITHUB_PROJECT=	esip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/esip/
COMMENT=	ProcessOne SIP server component in Erlang
LICENSE=	apache-2.0

DEPENDS+=	erlang-fast_tls>=1.1.21:../../security/erlang-fast_tls
DEPENDS+=	erlang-p1_utils>=1.0.26:../../misc/erlang-p1_utils
DEPENDS+=	erlang-stun>=1.2.14:../../net/erlang-stun

GNU_CONFIGURE=	yes

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
