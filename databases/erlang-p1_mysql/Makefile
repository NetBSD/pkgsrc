# $NetBSD: Makefile,v 1.3 2016/01/16 18:51:35 fhajny Exp $

DISTNAME=	p1_mysql-1.0.0
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/mysql/
COMMENT=	Erlang MySQL driver
LICENSE=	modified-bsd

GITHUB_PROJECT=	mysql
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
