# $NetBSD: Makefile,v 1.2 2002/09/09 01:19:37 markd Exp $

DISTNAME=	R-recommended-1.5.1
CATEGORIES=	math
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	markd@netbsd.org
HOMEPAGE=	http://www.R-project.org/
COMMENT=	Recommended packages "meta-package" for R

DEPENDS+=	R-KernSmooth>=2.22.7:../../math/R-KernSmooth
DEPENDS+=	R-VR>=7.0.3:../../math/R-VR
DEPENDS+=	R-boot>=1.2.8:../../math/R-boot
DEPENDS+=	R-cluster>=1.4.2:../../math/R-cluster
DEPENDS+=	R-foreign>=0.5.5:../../math/R-foreign
DEPENDS+=	R-grid>=0.6:../../math/R-grid
DEPENDS+=	R-lattice>=0.5.3:../../math/R-lattice
DEPENDS+=	R-mgcv>=0.8.1:../../math/R-mgcv
DEPENDS+=	R-nlme>=3.1.27:../../math/R-nlme
DEPENDS+=	R-rpart>=3.1.7:../../math/R-rpart
DEPENDS+=	R-survival>=2.9.4:../../math/R-survival

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SRC=	/dev/null

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
