# $NetBSD: Makefile,v 1.3 2022/10/15 12:11:03 triaxx Exp $

DISTNAME=	yconf-1.0.14
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/yconf
COMMENT=	YAML configuration processor
LICENSE=	apache-2.0

DEPENDS+=	erlang-fast_yaml>=1.0.34:../../textproc/erlang-fast_yaml

GITHUB_PROJECT=	yconf

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
