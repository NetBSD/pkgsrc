# $NetBSD: Makefile,v 1.13 2022/10/14 19:22:11 triaxx Exp $

DISTNAME=	p1_pgsql-1.1.19
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/p1_pgsql/
COMMENT=	Pure Erlang PostgreSQL driver
LICENSE=	erlang-public-license

DEPENDS=	erlang-xmpp>=1.6.0:../../net/erlang-xmpp

GITHUB_PROJECT=	p1_pgsql

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
