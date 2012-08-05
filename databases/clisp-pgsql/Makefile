# $NetBSD: Makefile,v 1.2 2012/08/05 10:02:09 obache Exp $
#

CLISP_MODULE=	postgresql

PKGNAME=	clisp-pgsql-$(CLISP_VERSION)
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP PostgreSQL module

MAKE_JOBS_SAFE=	no


.include "../../lang/clisp/module.mk"

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
