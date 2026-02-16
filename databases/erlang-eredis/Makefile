# $NetBSD: Makefile,v 1.8 2026/02/16 21:12:59 gdt Exp $

DISTNAME=	eredis-1.2.0
PKGREVISION=	1
CATEGORIES=	databases
#MASTER_SITES=	${MASTER_SITE_GITHUB:=Nordix/}
# 1.2.0 is at wooga; newer is at Nordix
MASTER_SITES=	${MASTER_SITE_GITHUB:=wooga/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Nordix/eredis/
# previous homepage, now archived
#HOMEPAGE=	https://github.com/wooga/eredis/
COMMENT=	Erlang Redis client
LICENSE=	mit

GITHUB_PROJECT=	eredis
GITHUB_TAG=	v${PKGVERSION_NOREV}

ERL_MOD_DIR=	lib/erlang/lib/${DISTNAME}

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
