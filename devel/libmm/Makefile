# $NetBSD: Makefile,v 1.2 2001/10/23 14:40:36 jlam Exp $
#

DISTNAME=	mm-1.1.3
PKGNAME=	libmm-1.1.3
CATEGORIES=	devel
MASTER_SITES=	http://www.engelschall.com/sw/mm/

MAINTAINER=	cjones@netbsd.org
HOMEPAGE=	http://www.engelschall.com/sw/mm/
COMMENT=	Portable abstraction layer for shared memory

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
