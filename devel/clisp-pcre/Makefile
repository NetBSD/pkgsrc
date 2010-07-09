# $NetBSD: Makefile,v 1.1.1.1 2010/07/09 18:59:48 asau Exp $
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

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
