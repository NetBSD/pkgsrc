# $NetBSD: Makefile,v 1.3 2012/03/03 00:12:53 wiz Exp $
#

CLISP_MODULE=	pcre

PKGNAME=	clisp-$(CLISP_MODULE)-$(CLISP_VERSION)
PKGREVISION=	1
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
