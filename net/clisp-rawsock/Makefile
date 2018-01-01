# $NetBSD: Makefile,v 1.3 2018/01/01 18:16:38 rillig Exp $
#

CLISP_MODULE=	rawsock

PKGNAME=	clisp-${CLISP_MODULE}-${CLISP_VERSION}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP rawsock module

MAKE_JOBS_SAFE=	no

.include "../../lang/clisp/module.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
