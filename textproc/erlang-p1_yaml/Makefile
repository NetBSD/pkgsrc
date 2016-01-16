# $NetBSD: Makefile,v 1.3 2016/01/16 18:57:43 fhajny Exp $

DISTNAME=	p1_yaml-1.0.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/p1_yaml/
COMMENT=	Erlang wrapper for libyaml C library
LICENSE=	apache-2.0

DEPENDS+=	erlang-p1_utils>=1.0.2:../../misc/erlang-p1_utils

GITHUB_PROJECT=	p1_yaml

GNU_CONFIGURE=	yes

.include "../../textproc/libyaml/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
