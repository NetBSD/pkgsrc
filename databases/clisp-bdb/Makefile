# $NetBSD: Makefile,v 1.2 2011/04/20 22:12:50 hans Exp $
#

CLISP_MODULE=	berkeley-db

PKGNAME=	clisp-bdb-$(CLISP_VERSION)
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=	hans@netbsd.org
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP Berkeley DB module

SUBST_CLASSES+=			db4-libname
SUBST_STAGE.db4-libname=	pre-configure
SUBST_FILES.db4-libname=	modules/berkeley-db/configure
SUBST_SED.db4-libname=		-e "/names_next_round='db '/s/db/db4/"


MAKE_JOBS_SAFE=	no

.include "../../lang/clisp/module.mk"

.include "../../databases/db4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
