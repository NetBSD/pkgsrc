# $NetBSD: Makefile,v 1.11 2004/04/25 12:07:12 dillo Exp $
#

DISTNAME=	guile-oops-0.9.0
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=guile/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/guile/
COMMENT=	CLOS-like object system for Guile

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
INFO_FILES=		goops.info

.include "../../lang/guile14/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
