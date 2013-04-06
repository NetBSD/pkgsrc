# $NetBSD: Makefile,v 1.3 2013/04/06 13:09:24 rodent Exp $
#

CLISP_MODULE=	wildcard

PKGNAME=	clisp-$(CLISP_MODULE)-$(CLISP_VERSION)
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=	hans@NetBSD.org
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP wildcard matching module

MAKE_JOBS_SAFE=	no

post-extract:
	(cd ${WRKSRC} && cp -p src/gllib/alloca.in.h src/gllib/alloca.h)

.include "../../lang/clisp/module.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
