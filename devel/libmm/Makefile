# $NetBSD: Makefile,v 1.2.2.1 2002/06/21 23:05:07 jlam Exp $
#

DISTNAME=	mm-1.1.3
PKGNAME=	libmm-1.1.3
CATEGORIES=	devel
MASTER_SITES=	http://www.engelschall.com/sw/mm/

MAINTAINER=	cjones@netbsd.org
HOMEPAGE=	http://www.engelschall.com/sw/mm/
COMMENT=	Portable abstraction layer for shared memory

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
