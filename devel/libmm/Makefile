# $NetBSD: Makefile,v 1.1.1.1 2001/07/14 23:06:26 cjones Exp $
#

DISTNAME=	mm-1.1.3
PKGNAME=	libmm-1.1.3
CATEGORIES=	devel
MASTER_SITES=	http://www.engelschall.com/sw/mm/

MAINTAINER=	cjones@netbsd.org
HOMEPAGE=	http://www.engelschall.com/sw/mm/
COMMENT=	Portable abstraction layer for shared memory

HAS_CONFIGURE=	YES
GNU_CONFIGURE=	YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
