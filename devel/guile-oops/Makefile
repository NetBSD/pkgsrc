# $NetBSD: Makefile,v 1.6 2003/01/07 11:40:23 uebayasi Exp $
#

DISTNAME=	guile-oops-0.9.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=guile/}

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.gnu.org/software/guile/
COMMENT=	CLOS-like object system for Guile

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../lang/guile14/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
