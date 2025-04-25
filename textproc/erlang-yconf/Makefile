# $NetBSD: Makefile,v 1.5 2025/04/25 11:37:24 gdt Exp $

DISTNAME=	yconf-1.0.18
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}
GITHUB_PROJECT=	yconf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/yconf
COMMENT=	YAML configuration processor
LICENSE=	apache-2.0

DEPENDS+=	erlang-fast_yaml>=1.0.37:../../textproc/erlang-fast_yaml

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
