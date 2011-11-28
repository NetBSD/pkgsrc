# $NetBSD: Makefile,v 1.3 2011/11/28 22:51:41 marino Exp $
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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
