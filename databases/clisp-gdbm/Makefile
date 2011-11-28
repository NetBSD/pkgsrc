# $NetBSD: Makefile,v 1.3 2011/11/28 22:55:02 marino Exp $
#

CLISP_MODULE=	gdbm

PKGNAME=	clisp-$(CLISP_MODULE)-$(CLISP_VERSION)
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP GNU database manager module

MAKE_JOBS_SAFE=	no

.include "../../lang/clisp/module.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
