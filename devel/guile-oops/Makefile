# $NetBSD: Makefile,v 1.17 2005/10/16 23:40:36 gdt Exp $
#

DISTNAME=	guile-oops-0.9.0
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=guile/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/guile/
COMMENT=	CLOS-like object system for Guile 1.4

CONFLICTS=	guile>1.4

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
INFO_FILES=		goops.info

.include "../../lang/guile14/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
