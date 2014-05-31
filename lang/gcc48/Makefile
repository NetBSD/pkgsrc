# $NetBSD: Makefile,v 1.16 2014/05/31 13:06:25 ryoon Exp $

GCC_PKGNAME=	gcc48
.include	"version.mk"

PKGNAME=	${GCC_PKGNAME}-${GCC48_DIST_VERSION}
CATEGORIES=	lang

MAINTAINER=	sbd@NetBSD.org
HOMEPAGE=	http://gcc.gnu.org/
COMMENT=	The GNU Compiler Collection (GCC) - 4.8 Release Series
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

META_PACKAGE=	yes

DEPENDS+=	gcc48-libs-[0-9]*:../../lang/gcc48-libs
DEPENDS+=	gcc48-cc++-[0-9]*:../../lang/gcc48-cc++
DEPENDS+=	gcc48-fortran-[0-9]*:../../lang/gcc48-fortran
DEPENDS+=	gcc48-objc-[0-9]*:../../lang/gcc48-objc

.include "../../mk/bsd.pkg.mk"
