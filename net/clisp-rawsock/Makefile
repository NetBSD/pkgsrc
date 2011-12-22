# $NetBSD: Makefile,v 1.2 2011/12/22 22:09:35 marino Exp $
#

CLISP_MODULE=	rawsock

PKGNAME=	clisp-$(CLISP_MODULE)-$(CLISP_VERSION)
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP rawsock module

MAKE_JOBS_SAFE=	no

.include "../../lang/clisp/module.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
