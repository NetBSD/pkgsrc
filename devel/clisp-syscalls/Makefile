# $NetBSD: Makefile,v 1.1.1.1 2010/07/09 21:17:32 asau Exp $
#

CLISP_MODULE=	syscalls

PKGNAME=	clisp-$(CLISP_MODULE)-$(CLISP_VERSION)
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP, a Common Lisp implementation

MAKE_JOBS_SAFE=	no

.include "../../lang/clisp/module.mk"

.include "../../mk/bsd.pkg.mk"
