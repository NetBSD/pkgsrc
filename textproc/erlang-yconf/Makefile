# $NetBSD: Makefile,v 1.2 2021/05/20 15:43:59 triaxx Exp $

DISTNAME=	yconf-1.0.11
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/yconf
COMMENT=	YAML configuration processor
LICENSE=	apache-2.0

DEPENDS+=	erlang-fast_yaml>=1.0.29:../../textproc/erlang-fast_yaml

GITHUB_PROJECT=	yconf

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
