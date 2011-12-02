# $NetBSD: Makefile,v 1.2 2011/12/02 20:47:49 marino Exp $
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
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
