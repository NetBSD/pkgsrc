# $NetBSD: Makefile,v 1.4 2018/01/01 18:16:35 rillig Exp $
#

CLISP_MODULE=	postgresql

PKGNAME=	clisp-pgsql-${CLISP_VERSION}
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP PostgreSQL module

MAKE_JOBS_SAFE=	no


.include "../../lang/clisp/module.mk"

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
