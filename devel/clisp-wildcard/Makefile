# $NetBSD: Makefile,v 1.1 2011/04/20 18:50:01 hans Exp $
#

CLISP_MODULE=	wildcard

PKGNAME=	clisp-$(CLISP_MODULE)-$(CLISP_VERSION)
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=	hans@netbsd.org
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP wildcard matching module

MAKE_JOBS_SAFE=	no

post-extract:
	(cd ${WRKSRC} && cp -p src/gllib/alloca.in.h src/gllib/alloca.h)

.include "../../lang/clisp/module.mk"
.include "../../mk/bsd.pkg.mk"
