# $NetBSD: Makefile,v 1.9 2003/07/13 13:51:14 wiz Exp $
#

DISTNAME=	guile-oops-0.9.0
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=guile/}

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.gnu.org/software/guile/
COMMENT=	CLOS-like object system for Guile

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_NEW_TEXINFO=	YES
INFO_FILES=		goops.info

.include "../../lang/guile14/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
