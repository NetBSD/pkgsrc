# $NetBSD: Makefile,v 1.7 2003/07/17 21:31:35 grant Exp $
#

DISTNAME=	mm-1.2.2
PKGNAME=	lib${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ossp.org/pkg/lib/mm/

MAINTAINER=	cjones@NetBSD.org
HOMEPAGE=	http://www.ossp.org/pkg/lib/mm/
COMMENT=	Portable abstraction layer for shared memory

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
