# $NetBSD: Makefile,v 1.2 2010/09/17 09:35:58 asau Exp $
#

CLISP_MODULE=	syscalls

PKGNAME=	clisp-$(CLISP_MODULE)-$(CLISP_VERSION)
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP, a Common Lisp implementation

MAKE_JOBS_SAFE=	no

.include "../../lang/clisp/module.mk"

.include "../../mk/bsd.pkg.mk"
