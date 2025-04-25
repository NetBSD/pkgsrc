# $NetBSD: Makefile,v 1.15 2025/04/25 11:29:22 gdt Exp $

DISTNAME=	p1_pgsql-1.1.32
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}
GITHUB_PROJECT=	p1_pgsql

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/p1_pgsql
COMMENT=	Pure Erlang PostgreSQL driver
LICENSE=	erlang-public-license

DEPENDS=	erlang-xmpp>=1.8.2:../../net/erlang-xmpp

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
