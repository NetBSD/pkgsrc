# $NetBSD: Makefile,v 1.1.1.1 2002/04/23 01:43:43 markd Exp $

DISTNAME=	R-recommended-1.4.1
CATEGORIES=	math
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	markd@netbsd.org
HOMEPAGE=	http://www.R-project.org/
COMMENT=	Recommended packages "meta-package" for R

DEPENDS+=	R-KernSmooth-2.22.7:../../math/R-KernSmooth
DEPENDS+=	R-VR-6.3.2:../../math/R-VR
DEPENDS+=	R-boot-1.2.7:../../math/R-boot
DEPENDS+=	R-cluster-1.4.0:../../math/R-cluster
DEPENDS+=	R-foreign-0.4.9:../../math/R-foreign
DEPENDS+=	R-mgcv-0.7.1:../../math/R-mgcv
DEPENDS+=	R-nlme-3.1.23:../../math/R-nlme
DEPENDS+=	R-rpart-3.1.5:../../math/R-rpart
DEPENDS+=	R-survival-2.8.2:../../math/R-survival

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SRC=	/dev/null

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
