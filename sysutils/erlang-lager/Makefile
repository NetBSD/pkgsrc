# $NetBSD: Makefile,v 1.9 2021/05/21 11:24:16 triaxx Exp $

DISTNAME=	lager-3.9.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=erlang-lager/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/erlang-lager/lager/
COMMENT=	Logging framework for Erlang/OTP
LICENSE=	apache-2.0

DEPENDS+=	erlang-goldrush>=0.1.9:../../sysutils/erlang-goldrush

GITHUB_PROJECT=	lager
GITHUB_TAG=	${PKGVERSION_NOREV}

post-extract:
	# Remove dependency handling
	${RM} -f ${WRKSRC}/rebar.config.script

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
