# $NetBSD: Makefile,v 1.3 2026/02/15 18:22:34 gdt Exp $

DISTNAME=	p1_xmlrpc-1.15.1
PKGNAME=	erlang-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/p1_xmlrpc/
COMMENT=	Erlang XMLRPC implementation with SSL, cookies, Authentication
LICENSE=	2-clause-bsd

GITHUB_PROJECT=	p1_xmlrpc

ERL_MOD_DIR=	lib/erlang/lib/${DISTNAME}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${REBAR} compile

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
