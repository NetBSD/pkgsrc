# $NetBSD: Makefile,v 1.3 2016/01/16 19:19:04 fhajny Exp $

DISTNAME=	xmlrpc-1.15
PKGNAME=	erlang-${DISTNAME}.20150506
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=rds13/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/rds13/xmlrpc/
COMMENT=	Erlang XMLRPC implementation with SSL, cookies, Authentication
LICENSE=	2-clause-bsd

GITHUB_PROJECT=	xmlrpc
GITHUB_TAG=	42e6e96a0fe7106830274feed915125feb1056f3
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

ERL_MOD_DIR=	lib/erlang/lib/${DISTNAME}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${REBAR} compile

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
