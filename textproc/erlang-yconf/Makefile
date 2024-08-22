# $NetBSD: Makefile,v 1.4 2024/08/22 06:04:44 adam Exp $

DISTNAME=	yconf-1.0.16
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
