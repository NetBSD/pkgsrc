# $NetBSD: Makefile,v 1.3 2013/04/06 14:09:32 rodent Exp $
#

CLISP_MODULE=	zlib

PKGNAME=	clisp-${CLISP_MODULE}-${CLISP_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP zlib module

MAKE_JOBS_SAFE=	no

.include "../../lang/clisp/module.mk"

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
