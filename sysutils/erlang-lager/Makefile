# $NetBSD: Makefile,v 1.2 2016/01/16 17:37:37 fhajny Exp $

DISTNAME=	lager-3.0.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=basho/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/basho/lager/
COMMENT=	Logging framework for Erlang/OTP
LICENSE=	apache-2.0

DEPENDS+=	erlang-goldrush>=0.1.7:../../sysutils/erlang-goldrush

GITHUB_PROJECT=	lager
GITHUB_TAG=	${PKGVERSION_NOREV}

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
