# $NetBSD: Makefile,v 1.2 2011/12/02 20:45:27 marino Exp $
#

CLISP_MODULE=	pcre

PKGNAME=	clisp-$(CLISP_MODULE)-$(CLISP_VERSION)
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP PCRE module

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no


.include "../../lang/clisp/module.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
