# $NetBSD: Makefile,v 1.18 2026/08/06 11:12:29 gdt Exp $

DISTNAME=	p1_pgsql-1.1.41
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}
GITHUB_PROJECT=	p1_pgsql

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/p1_pgsql
COMMENT=	Pure Erlang PostgreSQL driver
LICENSE=	erlang-public-license

DEPENDS+=	erlang-stringprep>=1.0.33:../../textproc/erlang-stringprep

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
