# $NetBSD: Makefile,v 1.6 2025/04/25 11:13:52 gdt Exp $

DISTNAME=	eredis-1.2.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=wooga/}
#MASTER_SITES=	${MASTER_SITE_GITHUB:=Nordix/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wooga/eredis/
#HOMEPAGE=	https://github.com/Nordix/eredis/
COMMENT=	Erlang Redis client
LICENSE=	mit

GITHUB_PROJECT=	eredis
GITHUB_TAG=	v${PKGVERSION_NOREV}

ERL_MOD_DIR=	lib/erlang/lib/${DISTNAME}

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
