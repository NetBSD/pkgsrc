# $NetBSD: Makefile,v 1.14 2004/10/14 15:31:40 tv Exp $
#

DISTNAME=	guile-oops-0.9.0
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=guile/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/guile/
COMMENT=	CLOS-like object system for Guile

CONFLICTS=	guile>1.4

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
INFO_FILES=		goops.info

.include "../../lang/guile14/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
