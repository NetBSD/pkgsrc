# $NetBSD: Makefile,v 1.3 2016/01/16 18:52:46 fhajny Exp $

DISTNAME=	p1_pgsql-1.0.0
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/pgsql/
COMMENT=	Pure Erlang PostgreSQL driver
LICENSE=	erlang-public-license

GITHUB_PROJECT=	pgsql
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
