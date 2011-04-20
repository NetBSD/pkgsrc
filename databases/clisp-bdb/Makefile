# $NetBSD: Makefile,v 1.1 2011/04/20 18:31:36 hans Exp $
#

CLISP_MODULE=	berkeley-db

PKGNAME=	clisp-bdb-$(CLISP_VERSION)
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=	hans@netbsd.org
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP Berkeley DB module

MAKE_JOBS_SAFE=	no

.include "../../lang/clisp/module.mk"

BUILDLINK_TRANSFORM+=   l:db:db4
.include "../../databases/db4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
